%{
#include <stdio.h>
#include <string.h>
char oldword[128],newword[128];
%}
%%
[A-Za-z0-9_]+ { if(!strcmp(yytext,oldword))fputs(newword,stdout);else ECHO; }
.|\n { ECHO; }
%%
int main(int argc,char **argv){if(argc<3){fprintf(stderr,"Usage: %s oldword newword < inputfile\n",argv[0]);return 1;}snprintf(oldword,sizeof oldword,"%s",argv[1]);snprintf(newword,sizeof newword,"%s",argv[2]);yylex();return 0;}
int yywrap(void){return 1;}
