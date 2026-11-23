%{
#include <stdio.h>
int constants=0,macros=0,headers=0;
%}
%%
^[ \t]*#[ \t]*define[ \t]+[A-Za-z_][A-Za-z0-9_]*[ \t]+[^ \t\n]+ { macros++; printf("Macro: %s\n",yytext); }
^[ \t]*#[ \t]*include[ \t]*[<"][^>"]+[>"] { headers++; printf("Header: %s\n",yytext); }
\"([^\\\"]|\\.)*\"      { constants++; printf("String constant: %s\n",yytext); }
[0-9]+(\.[0-9]+)?       { constants++; printf("Numeric constant: %s\n",yytext); }
.|\n                    ;
%%
int main(int argc,char **argv){if(argc>1){yyin=fopen(argv[1],"r");if(!yyin){perror(argv[1]);return 1;}}yylex();printf("Constants: %d\nMacros: %d\nHeader files: %d\n",constants,macros,headers);return 0;}
int yywrap(void){return 1;}
