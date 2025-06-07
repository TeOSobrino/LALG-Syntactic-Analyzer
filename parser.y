%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

// Nó da ASA
typedef struct ASTNode {
    char *type;
    char *value;
    struct ASTNode **children;
    int child_count;
    int child_capacity;
} ASTNode;

// Protótipo das Funções
void print_usage(void);
void print_options(void);
void print_invalid(char** argv, int arg_num);
ASTNode* create_node(const char* type, const char* value);
void add_child(ASTNode* parent, ASTNode* child);
void print_ast(ASTNode* node, int indent, FILE* output);
void free_ast(ASTNode* node);

void yyerror(const char *msg) {
    fprintf(stderr, "\nErro de sintaxe na linha %d próximo a '%s':\n", yylineno, yytext);
}

ASTNode* root = NULL;
%}

%union {
    int ival;
    float fval;
    char *sval;
    struct ASTNode *node;
}

%token <ival> NUM_INT
%token <fval> NUM_REAL
%token <sval> IDENT

%token PROGRAM BEGIN_BLOCK END CONST VAR PROCEDURE IF THEN ELSE WHILE DO READ WRITE FOR TO ASSIGN
%token INTEGER REAL
%token NE GE LE
%nonassoc LOWER_THAN_ELSE // definir a precedência de if-then-else > if

%type <node> programa corpo dc dc_c dc_v dc_p lista_const const_item lista_var var_item
%type <node> variaveis mais_var proc_decl parametros lista_par mais_par corpo_p dc_loc
%type <node> comandos comando_lista comando condicao expressao termo fator numero
%type <node> relacao outros_termos op_ad mais_fatores op_mul op_un tipo_var
%type <node> lista_arg argumentos mais_ident write_list write_item

%left '+' '-'
%left '*' '/'

%%

programa:
    PROGRAM IDENT ';' corpo '.' {
        $$ = create_node("PROGRAMA", $2);
        add_child($$, $4);
        root = $$;
        ASTNode* no_fim = create_node("FIM_PROGRAMA", NULL);
        add_child($$, no_fim); // coloca o nó fim como filho do início
        printf("Análise sintática concluída com sucesso.\n");
    }
    | error '.' {
        fprintf(stderr,"\tErro na inicialização do programa. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = create_node("ERROR_PROGRAM", NULL);
    }
;

corpo:
    dc BEGIN_BLOCK comandos END {
        $$ = create_node("CORPO", NULL);
        add_child($$, $1);
        add_child($$, $3);
    }
;

dc:
    dc_c dc_v dc_p {
        $$ = create_node("DECLARAÇÕES", NULL);
        if ($1) add_child($$, $1);
        if ($2) add_child($$, $2);
        if ($3) add_child($$, $3);
    }
;

dc_c:
    CONST lista_const {
        $$ = create_node("DECL_CONST", NULL);
        add_child($$, $2);
    }
    | /* vazio */ { $$ = NULL; }
;

lista_const:
    const_item ';' lista_const {
        $$ = create_node("CONST_LIST", NULL);
        add_child($$, $1);
        if ($3) add_child($$, $3);
    }
    | const_item ';' {
        $$ = $1;
    }
    | error ';' lista_const {
        fprintf(stderr, "\tErro em declaração de constante. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = $3;
    }
    | error ';' {
        fprintf(stderr, "\tErro em declaração de constante. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = NULL;
    }
;

const_item:
    IDENT '=' numero {
        $$ = create_node("CONST_ASSIGN", $1);
        add_child($$, $3);
    }
    | IDENT error numero {
        fprintf(stderr, "\tErro na atribuição de constante: esperado '='. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = create_node("CONST_ASSIGN", $1);
        add_child($$, $3);
    }
;

dc_v:
    VAR lista_var {
        $$ = create_node("DECLARAÇÃO_VARS", NULL);
        add_child($$, $2);
    }
    | /* vazio */ { $$ = NULL; }
;

lista_var:
    var_item ';' lista_var {
        $$ = create_node("LISTA_VAR", NULL);
        add_child($$, $1);
        if ($3) add_child($$, $3);
    }
    | var_item ';' {
        $$ = $1;
    }
    | error ';' lista_var {
        fprintf(stderr, "\tErro em declaração de variável. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = $3;
    }
    | error ';' {
        fprintf(stderr, "\tErro em declaração de variável. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = NULL;
    }
;

var_item:
    variaveis ':' tipo_var {
        $$ = create_node("LISTA_VARS", NULL);
        add_child($$, $1);
        add_child($$, $3);
    }
;

tipo_var:
    REAL { $$ = create_node("TIPO", "real"); }
    | INTEGER { $$ = create_node("TIPO", "integer"); }
;

variaveis:
    IDENT mais_var {
        $$ = create_node("VARIÁVEL", $1);
        if ($2) add_child($$, $2);
    }
    | error variaveis { // Recuperação para token inválido depois de comando
        fprintf(stderr, "\tErro em declaração de variável: esperado IDENT. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; 
        $$ = $2;
    }
;

mais_var:
    ',' variaveis {
        $$ = $2;
    }
    | ',' error mais_var { // Recuperação de erro: identificador inválido depois de ','
        fprintf(stderr, "\tErro em declaração de variável: esperado IDENT após ','. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; 
    }
    | /* vazio */ { $$ = NULL; }
;

dc_p:
    proc_decl dc_p {
        $$ = create_node("PROC_LIST", NULL);
        add_child($$, $1);
        if ($2) add_child($$, $2);
    }
    | error ';' dc_p {
        fprintf(stderr, "\tErro em declaração de procedimento. Tentando recuperar. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = $3;
    }
    | /* vazio */ { $$ = NULL; }
;

proc_decl:
    PROCEDURE IDENT parametros ';' corpo_p {
        $$ = create_node("PROCEDURE", $2);
        if ($3) add_child($$, $3);
        add_child($$, $5);
    }
;

parametros:
    '(' lista_par ')' {
        $$ = create_node("PARAMETERS", NULL);
        if ($2) add_child($$, $2);
    }
    | /* vazio */ { $$ = NULL; }
;

lista_par:
    variaveis ':' tipo_var mais_par {
        $$ = create_node("PARAM_LIST", NULL);
        ASTNode* param = create_node("PARAMETER", NULL);
        add_child(param, $1);
        add_child(param, $3);
        add_child($$, param);
        if ($4) add_child($$, $4);
    }
    | /* vazio */ { $$ = NULL; }
;

mais_par:
    ';' lista_par {
        $$ = $2;
    }
    | /* vazio */ { $$ = NULL; }
;

corpo_p:
    dc_loc BEGIN_BLOCK comandos END ';' {
        $$ = create_node("CORPO_BLOCO", NULL);
        if ($1) add_child($$, $1);
        add_child($$, $3);
    }
;

dc_loc:
    dc_v { $$ = $1; }
;

lista_arg:
    '(' argumentos ')' {
        $$ = create_node("ARGUMENTS", NULL);
        if ($2) add_child($$, $2);
    }
    | /* vazio */ { $$ = NULL; }
;

argumentos:
    IDENT mais_ident {
        $$ = create_node("ARG_LIST", $1);
        if ($2) add_child($$, $2);
    }
;

mais_ident:
    ';' argumentos {
        $$ = $2;
    }
    | /* vazio */ { $$ = NULL; }
;

comandos:
    comando_lista { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
;

comando_lista:
    comando ';' comando_lista { // Exige ; entre comandos
        $$ = create_node("LISTA_CMDS", NULL);
        add_child($$, $1);
        if ($3) add_child($$, $3);
    }
    | comando ';' { // Ultimo comando com ;
        $$ = $1;
    }
    | comando error comando_lista { // Erro: falta ;
        fprintf(stderr, "\tErro de terminação: esperado ';' após comando. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; // Descarta um token inválido e tenta recuperar
        $$ = create_node("LISTA_CMDS", NULL);
        add_child($$, $1); // Adiciona o comando que está sendo parseado
        if ($3) add_child($$, $3); // Adiciona o resto da lista
    }
    | comando error { // Erro: falta ;
        fprintf(stderr, "\tErro de terminação: esperado ';' após comando. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        $$ = $1;
    }
;

write_list:
    write_item {
        $$ = $1;
    }
;

write_item:
    variaveis {
        $$ = $1;
    }
    | expressao {
        $$ = $1;
    }
;

comando:
    READ '(' variaveis ')' {
        $$ = create_node("read", NULL);
        add_child($$, $3);
    }
    | WRITE '(' write_list ')' {
        $$ = create_node("write", NULL);
        add_child($$, $3);
    }
    | WHILE '(' condicao ')' DO comando {
        $$ = create_node("while", NULL);
        add_child($$, $3);
        add_child($$, $6);
    }
    | IF condicao THEN comando ELSE comando {
        $$ = create_node("if", NULL);
        add_child($$, $2); // Condição
        add_child($$, $4); // bloco após o then

        // nó de else
        ASTNode* else_node = create_node("else", NULL);
        add_child(else_node, $6); // boloco após o else
        add_child($$, else_node); // coloca o nó else como filho do nó if
    }
    | IF condicao THEN comando %prec LOWER_THAN_ELSE {
        $$ = create_node("if", NULL);
        add_child($$, $2);
        add_child($$, $4);
    }
    | IDENT ASSIGN expressao {
        $$ = create_node("assign", $1);
        add_child($$, $3);
    }
    | IDENT lista_arg {
        $$ = create_node("call", $1);
        if ($2) add_child($$, $2);
    }
    | BEGIN_BLOCK comandos END {
        $$ = create_node("bloco", NULL);
        if ($2) add_child($$, $2);
        ASTNode* end_block_node = create_node("fim_bloco", NULL);
        add_child($$, end_block_node); 
    }
    | FOR IDENT ASSIGN expressao TO expressao DO comando {
        $$ = create_node("for", $2);
        add_child($$, $4);
        add_child($$, $6);
        add_child($$, $8);
    }
    | error ';' {
        fprintf(stderr, "\tErro em comando. Linha %d : Erro de sintaxe.\n", yylineno); 
        yyerrok;
        $$ = create_node("ERROR_STMT", NULL);
    }
;

condicao:
    expressao relacao expressao {
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
    }
;

relacao:
    '=' { $$ = create_node("=", NULL); }
    | NE { $$ = create_node("!=", NULL); }
    | GE { $$ = create_node(">=", NULL); }
    | LE { $$ = create_node("<=", NULL); }
    | '>' { $$ = create_node(">", NULL); }
    | '<' { $$ = create_node("<", NULL); }
;

expressao:
    termo outros_termos {
        if ($2) {
            add_child($2, $1);
            $$ = $2;
        } else {
            $$ = $1;
        }
    }
;

outros_termos:
    op_ad termo outros_termos {
        add_child($1, $2);
        if ($3) {
            add_child($3, $1);
            $$ = $3;
        } else {
            $$ = $1;
        }
    }
    | /* vazio */ { $$ = NULL; }
;

op_ad:
    '+' { $$ = create_node("+", NULL); }
    | '-' { $$ = create_node("-", NULL); }
;

termo:
    op_un fator mais_fatores {
        ASTNode* result = $2;
        if ($1) {
            add_child($1, $2);
            result = $1;
        }
        if ($3) {
            add_child($3, result);
            result = $3;
        }
        $$ = result;
    }
;

op_un:
    '+' { $$ = create_node("unary+", NULL); }
    | '-' { $$ = create_node("unary-", NULL); }
    | /* vazio */ { $$ = NULL; }
;

mais_fatores:
    op_mul fator mais_fatores {
        add_child($1, $2);
        if ($3) {
            add_child($3, $1);
            $$ = $3;
        } else {
            $$ = $1;
        }
    }
    | /* vazio */ { $$ = NULL; }
;

op_mul:
    '*' { $$ = create_node("*", NULL); }
    | '/' { $$ = create_node("/", NULL); }
;

fator:
    IDENT {
        $$ = create_node("identificador", $1);
    }
    | numero {
        $$ = $1;
    }
    | '(' expressao ')' {
        $$ = $2;
    }
;

numero:
    NUM_INT {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d", $1);
        $$ = create_node("integer", buffer);
    }
    | NUM_REAL {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%.2f", $1);
        $$ = create_node("real", buffer);
    }
;

%%

// Implementação da árvore sintática abstrata
ASTNode* create_node(const char* type, const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) {
        perror("Falha ao alocar memória para o nó da AST");
        exit(EXIT_FAILURE);
    }
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(ASTNode* parent, ASTNode* child) {
    if (!parent || !child) return;
    
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity = parent->child_capacity == 0 ? 4 : parent->child_capacity * 2;
        parent->children = realloc(parent->children, parent->child_capacity * sizeof(ASTNode*));
        if (!parent->children) {
            perror("Falha ao realocar memória para os filhos do nó");
            exit(EXIT_FAILURE);
        }
    }
    
    parent->children[parent->child_count++] = child;
}

void print_ast(ASTNode* node, int indent, FILE* output) {
    if (!node) return;
    
    for (int i = 0; i < indent; i++) fprintf(output, "  ");
    fprintf(output, "%s", node->type);
    if (node->value) fprintf(output, ": %s", node->value);
    fprintf(output, "\n");
    
    for (int i = 0; i < node->child_count; i++) {
        print_ast(node->children[i], indent + 1, output);
    }
}

void free_ast(ASTNode* node) {
    if (!node) return;
    
    for (int i = 0; i < node->child_count; i++) {
        free_ast(node->children[i]);
    }
    
    free(node->type);
    free(node->value);
    free(node->children);
    free(node);
}

void print_usage(void)
{
  printf("lalgc: Compilador de Pascal Simplificado (LALG).\n\tElaborado por Téo Sobrino Alves & Miller Anacleto Rocha.\n\tDisciplina SCC0217 - Compiladores, 2025.\n\nModos de Uso:\n\t./lalgc <opções> <arquivo_lalg>\n\t\tExemplo simples: ./lalgc -i <arquivo_lalg>\nUse a opção -h para ver o menu completo de opções.\n\n");
}

void print_options(void)
{
    printf("Opções:\n\t-h, --help\t\tImprime este menu de ajuda e termina.\n");
    printf("\t-i, --input <arquivo> \tIdentifica o arquivo de entrada.\n");
    printf("\t-t --tree [arquivo] \tImprime a árvore sintática abstrata. Caso nenhum arquivo seja fornecido, imprime em stdout.\n\n");
}

void print_invalid(char** argv, int arg_num)
{
    printf("Opção '%s' inválida.\n\tAjuda: ./lalgc -h ou --help\n\tmodo de uso: ./lalgc -i nome_arquivo_lalg\n\n", argv[arg_num]);
}

FILE* parse_argv(char** argv, int argc, int arg_num, FILE* tester)
{
    if(arg_num > argc) return NULL;
    if(argv[arg_num][0] == '-'){
        if(argv[arg_num][1] == 'h' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 'h')){ //Menu de ajuda
            print_usage();
            print_options();
            exit(0);
        }
        if(argv[arg_num][1] == 'i' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 'i')){//entrada
            tester = fopen(argv[arg_num+1], "r");
            if(!tester){ 
            fprintf(stderr, "\tNão foi possível abrir o arquivo '%s'.\n", argv[arg_num+1]);
            exit(1);
            }
            return tester;
        }
        if(argv[arg_num][1] == 't' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 't')){ //saída
            if (arg_num + 1 < argc && argv[arg_num+1][0] != '-') {
                 tester = fopen(argv[arg_num+1], "w+");
                 if(!tester){
                    fprintf(stderr, "\tNão foi possível abrir o arquivo de saída '%s'.\n", argv[arg_num+1]);
                    return stdout; // saída se torna stdout
                }
            } else {
                tester = stdout;
            }
            return tester;
        }     
        else{
            print_invalid(argv, arg_num);
            exit(1);
        }
    }
    else{
        print_invalid(argv, arg_num);
        exit(1);
    }
}

int main(int argc, char** argv) {

    FILE* input = NULL;
    FILE* output = NULL;
    FILE* tester;
    extern FILE* yyin;
    int arg_num = 1;

    if(argc < 2){
        print_usage();
        exit(1);
    }
    else{
        while(arg_num < argc){   
            if(argv[arg_num][0] == '-') {
                if(argv[arg_num][1] == 'i' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='i')){
                    if(arg_num + 1 < argc) {
                        input = fopen(argv[arg_num+1], "r");
                        if(!input) {
                            fprintf(stderr, "\tNão foi possível abrir o arquivo de entrada '%s'.\n", argv[arg_num+1]);
                            exit(1);
                        }
                        arg_num += 2;
                    } else {
                        print_invalid(argv, arg_num);
                        exit(1);
                    }
                } 
                else if(argv[arg_num][1] == 't' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='t')){
                    if(arg_num + 1 < argc && argv[arg_num+1][0] != '-') {
                        output = fopen(argv[arg_num+1], "w+");
                        if(!output) {
                            fprintf(stderr, "\tNão foi possível abrir o arquivo de saída '%s'. Usando stdout.\n", argv[arg_num+1]);
                            output = stdout;
                        }
                        arg_num += 2;
                    } else {
                        output = stdout;
                        arg_num++;
                    }
                }
                else if(argv[arg_num][1] == 'h' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='h')) {
                    print_usage();
                    print_options();
                    exit(0);
                }
                else {
                    print_invalid(argv, arg_num);
                    exit(1);
                }
            } else {
                print_invalid(argv, arg_num);
                exit(1);
            }
        }
    }

    if(input == NULL){
        fprintf(stderr, "\tNenhum arquivo de entrada especificado. Use a opção -i.\n");
        print_usage();
        exit(1);
    }

    yyin = input;
    printf("Iniciando análise sintática...\n");
    
    yyparse();
    
    fclose(input);
    
    if (root && output) {
        printf("Imprimindo a Árvore Sintática Abstrata...\n");
        print_ast(root, 0, output);
        if (output != stdout) {
            fclose(output);
        }
    }
    
    free_ast(root);

    return 0;
}