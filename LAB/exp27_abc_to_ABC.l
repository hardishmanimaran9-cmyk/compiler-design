%{
#include <stdio.h>
%}
%%
abc { printf("ABC"); }
.|\n { ECHO; }
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
