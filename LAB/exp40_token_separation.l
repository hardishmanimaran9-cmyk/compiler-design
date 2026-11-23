%{
#include <stdio.h>
%}
%%
"int"|"float"|"char"|"double"|"void"|"return"|"if"|"else"|"while"|"for"|"include" { printf("KEYWORD: %s\n",yytext); }
[A-Za-z_][A-Za-z0-9_]* { printf("IDENTIFIER: %s\n",yytext); }
[0-9]+(\.[0-9]+)? { printf("CONSTANT: %s\n",yytext); }
\"([^\\\"]|\\.)*\" { printf("STRING: %s\n",yytext); }
"=="|"!="|"<="|">="|"++"|"--"|"+"|"-"|"*"|"/"|"=" { printf("OPERATOR: %s\n",yytext); }
[(){};,<>] { printf("SPECIAL SYMBOL: %s\n",yytext); }
[ \t\n]+ ;
. { printf("UNKNOWN: %s\n",yytext); }
%%
int main(int argc,char **argv){if(argc>1){yyin=fopen(argv[1],"r");if(!yyin){perror(argv[1]);return 1;}}yylex();return 0;}
int yywrap(void){return 1;}
