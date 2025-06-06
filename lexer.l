%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
%}

digit       [0-9]+
real        {digit}"."{digit}+
id          [a-zA-Z_][a-zA-Z0-9_]*
ws          [ \t\r]+

%%

"program"       { return PROGRAM; }
"begin"         { return BEGIN_BLOCK; }
"end"           { return END; }
"const"         { return CONST; }
"var"           { return VAR; }
"procedure"     { return PROCEDURE; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"read"          { return READ; }
"write"         { return WRITE; }
"for"           { return FOR; }
"to"            { return TO; }
"integer"       { return INTEGER; }
"real"          { return REAL; }

{real}          { yylval.fval = atof(yytext); return NUM_REAL; }
{digit}         { yylval.ival = atoi(yytext); return NUM_INT; }
{id}            { yylval.sval = strdup(yytext); return IDENT; }

":="            { return ASSIGN; }
"<>"            { return NE; }
">="            { return GE; }
"<="            { return LE; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"="             { return '='; }
">"             { return '>'; }
"<"             { return '<'; }
":"             { return ':'; }
";"             { return ';'; }
","             { return ','; }
"."             { return '.'; }
"("             { return '('; }
")"             { return ')'; }

\n              { yylineno++; }
{ws}            { /* ignora espaço */ }
"{"[^}]*"}"     { /* ignora comentário */ }

.               { printf("Erro Léxico: Caractere inválido próximo à linha %d: %s\n", yylineno, yytext); }

%%

int yywrap() {
    return 1;
}