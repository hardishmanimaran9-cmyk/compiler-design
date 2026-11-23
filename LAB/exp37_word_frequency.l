%{
#include <stdio.h>
#include <string.h>
int count=0; char target[128];
%}
%%
[A-Za-z0-9_]+ { if(!strcmp(yytext,target)) count++; }
.|\n ;
%%
int main(int argc,char **argv){if(argc<2){fprintf(stderr,"Usage: %s word < sentence.txt\n",argv[0]);return 1;}strncpy(target,argv[1],sizeof target-1);yylex();printf("Frequency of %s: %d\n",target,count);return 0;}
int yywrap(void){return 1;}
