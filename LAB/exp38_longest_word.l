%{
#include <stdio.h>
int maxlen=0; char longest[256];
%}
%%
[A-Za-z0-9_]+ { if(yyleng>maxlen){maxlen=yyleng;snprintf(longest,sizeof longest,"%s",yytext);} }
.|\n ;
%%
int main(void){yylex();printf("Longest word: %s\nLength: %d\n",longest,maxlen);return 0;}
int yywrap(void){return 1;}
