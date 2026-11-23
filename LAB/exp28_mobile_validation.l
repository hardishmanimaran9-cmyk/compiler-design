%{
#include <stdio.h>
%}
%%
[+]?[6-9][0-9]{9} { printf("Valid mobile: %s\n",yytext); }
[0-9]+ { printf("Invalid mobile: %s\n",yytext); }
[ \t\n]+ ;
. ;
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
