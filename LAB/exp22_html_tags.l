%{
#include <stdio.h>
%}
%%
"</"?[A-Za-z][A-Za-z0-9]*[^>\n]*">" { printf("%s\n",yytext); }
.|\n ;
%%
int main(int argc,char **argv){if(argc>1){yyin=fopen(argv[1],"r");if(!yyin){perror(argv[1]);return 1;}}yylex();return 0;}
int yywrap(void){return 1;}
