%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

void yyerror(const char *msg) {
    fprintf(stderr, "Erro de sintaxe na linha %d próximo a '%s': %s\n", yylineno, yytext, msg);
}
%}

%union {
    int ival;
    float fval;
    char *sval;
}

%token <ival> NUM_INT
%token <fval> NUM_REAL
%token <sval> IDENT

%token PROGRAM BEGIN_BLOCK END CONST VAR PROCEDURE IF THEN ELSE WHILE DO READ WRITE FOR TO ASSIGN
%token INTEGER REAL
%token NE GE LE

%left '+' '-'
%left '*' '/'

%%

programa:
    PROGRAM IDENT ';' corpo '.' {
        printf("Análise sintática concluída com sucesso.\n");
    }
;

corpo:
    dc BEGIN_BLOCK comandos END
;

dc:
    dc_c dc_v dc_p
;

dc_c:
    CONST lista_const
    | /* vazio */
;

lista_const:
    const_item ';' lista_const
    | const_item ';'
    | error ';' lista_const {
        fprintf(stderr, "Erro na declaração de constante, recuperando no próximo ';'. Linha %d.\n", yylineno);
        yyerrok;
    }
    | error ';' {
        fprintf(stderr, "Erro na declaração de constante, recuperando no próximo ';'. Linha %d.\n", yylineno);
        yyerrok;
    }
;

const_item:
    IDENT '=' numero
    | IDENT error numero {
        fprintf(stderr, "Erro na declaração de constante: '=' esperado. Linha %d.\n", yylineno);
        yyerrok;
    }
;

dc_v:
    VAR lista_var
    | /* vazio */
;

lista_var:
    var_item ';' lista_var
    | var_item ';'
    | error ';' lista_var {
        fprintf(stderr, "Erro na declaração de variável, recuperando no próximo ';'. Linha %d.\n", yylineno);
        yyerrok;
    }
    | error ';' {
        fprintf(stderr, "Erro na declaração de variável, recuperando no próximo ';'. Linha %d.\n", yylineno);
        yyerrok;
    }
;

var_item:
    variaveis ':' tipo_var
;

tipo_var:
    REAL
    | INTEGER
;

variaveis:
    IDENT mais_var
;

mais_var:
    ',' variaveis
    | /* vazio */
;

dc_p:
    proc_decl dc_p
    | /* vazio */
;

proc_decl:
    PROCEDURE IDENT parametros ';' corpo_p
;

parametros:
    '(' lista_par ')'
    | /* vazio */
;

lista_par:
    variaveis ':' tipo_var mais_par
    | /* vazio */
;

mais_par:
    ';' lista_par
    | /* vazio */
;

corpo_p:
    dc_loc BEGIN_BLOCK comandos END ';'
;

dc_loc:
    dc_v
;

lista_arg:
    '(' argumentos ')'
    | /* vazio */
;

argumentos:
    IDENT mais_ident
;

mais_ident:
    ';' argumentos
    | /* vazio */
;

pfalsa:
    ELSE cmd
    | /* vazio */
;

comandos:
    comando_lista
    | /* vazio */
;

comando_lista:
    cmd_com_ponto_virgula comando_lista
    | cmd_com_ponto_virgula
;

cmd_com_ponto_virgula:
    cmd ';'
    | error ';' {
        fprintf(stderr, "Erro em comando, recuperando no próximo ';'. Linha %d.\n", yylineno);
        yyerrok;
    }
;

cmd:
    READ '(' variaveis ')'
    | WRITE '(' variaveis ')'
    | WHILE '(' condicao ')' DO cmd
    | IF condicao THEN cmd pfalsa
    | IDENT '=' expressao
    | IDENT lista_arg
    | BEGIN_BLOCK comandos END
    | FOR IDENT '=' expressao TO expressao DO cmd
    | error condicao THEN cmd pfalsa {
        fprintf(stderr, "Erro em comando: 'if' esperado antes da condição. Linha %d.\n", yylineno);
        yyerrok;
    }
;

cmd_simples:
    READ '(' variaveis ')'
    | WRITE '(' variaveis ')'
    | IDENT '=' expressao
    | IDENT lista_arg
    | BEGIN_BLOCK comandos END
;

condicao:
    expressao relacao expressao
;

relacao:
    '=' | NE | GE | LE | '>' | '<'
;

expressao:
    termo outros_termos
;

outros_termos:
    op_ad termo outros_termos
    | /* vazio */
;

op_ad:
    '+' | '-'
;

termo:
    op_un fator mais_fatores
;

op_un:
    '+' | '-' | /* vazio */
;

mais_fatores:
    op_mul fator mais_fatores
    | /* vazio */
;

op_mul:
    '*' | '/'
;

fator:
    IDENT
    | numero
    | '(' expressao ')'
;

numero:
    NUM_INT
    | NUM_REAL
;

%%

int main(void) {
    printf("Iniciando análise sintática...\n");
    yyparse();
    return 0;
}