%{
#include <stdio.h>
int comments=0;
FILE *out;
%}
%%
"//"[^\n]*        { comments++; }
"/*"([^*]|\*+[^*/])*\*+"/" { comments++; }
\n                { fputc('\n',out); }
.                 { fputc(yytext[0],out); }
%%
int main(int argc,char **argv){if(argc<3){fprintf(stderr,"Usage: %s input.c output.c\n",argv[0]);return 1;}yyin=fopen(argv[1],"r");out=fopen(argv[2],"w");if(!yyin||!out){perror("File");return 1;}yylex();fclose(yyin);fclose(out);printf("Comment blocks/lines removed: %d\n",comments);return 0;}
int yywrap(void){return 1;}
