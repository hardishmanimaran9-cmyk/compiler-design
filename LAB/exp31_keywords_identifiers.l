%{
#include <stdio.h>
#include <string.h>
const char *kw[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
int iskw(const char *s){for(int i=0;i<32;i++)if(!strcmp(s,kw[i]))return 1;return 0;}
%}
%%
[A-Za-z_][A-Za-z0-9_]* { printf("%s: %s\n",iskw(yytext)?"KEYWORD":"IDENTIFIER",yytext); }
[ \t\n]+ ;
. ;
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
