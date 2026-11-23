%{
#include <stdio.h>
%}
%%
[A-Z][A-Z0-9_]* { printf("%s\n",yytext); }
.|\n ;
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
