%{
#include <stdio.h>
int consonants=0;
%}
%%
[BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz] { consonants++; }
[A-Za-z] ;
.|\n ;
%%
int main(void){yylex();printf("Consonants: %d\n",consonants);return 0;}
int yywrap(void){return 1;}
