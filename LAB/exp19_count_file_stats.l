%{
#include <stdio.h>
int chars=0,lines=0,words=0;
%}
%%
"//".*                 ;
"/*"([^*]|\*+[^*/])*\*+"/" ;
[ \t\r]+               { chars += yyleng; }
\n                     { chars++; lines++; }
[^ \t\r\n]+            { chars += yyleng; words++; }
%%
int main(int argc,char **argv){if(argc>1){yyin=fopen(argv[1],"r");if(!yyin){perror(argv[1]);return 1;}}yylex();printf("Characters: %d\\nLines: %d\\nWords: %d\\n",chars,lines,words);return 0;}
int yywrap(void){return 1;}
