%{
#include <stdio.h>
%}
%%
https?://[A-Za-z0-9.-]+(:[0-9]+)?(/[A-Za-z0-9._~:/?#\[\]@!$&'()*+,;=%-]*)? { printf("Valid URL: %s\n",yytext); }
[^ \t\n]+ { printf("Invalid URL: %s\n",yytext); }
[ \t\n]+ ;
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
