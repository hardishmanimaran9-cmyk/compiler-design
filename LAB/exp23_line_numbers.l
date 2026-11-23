%{
#include <stdio.h>
int line=1, at_start=1;
%}
%%
\n              { ECHO; line++; at_start=1; }
.               { if(at_start) printf("%4d: ",line); ECHO; at_start=0; }
%%
int main(int argc,char **argv){if(argc>1){yyin=fopen(argv[1],"r");if(!yyin){perror(argv[1]);return 1;}}yylex();return 0;}
int yywrap(void){return 1;}
