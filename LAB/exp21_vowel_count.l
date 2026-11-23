%{
#include <stdio.h>
int vowels=0;
%}
%%
[AEIOUaeiou] { vowels++; }
[A-Za-z] ;
.|\n ;
%%
int main(void){yylex();printf("Vowels: %d\n",vowels);return 0;}
int yywrap(void){return 1;}
