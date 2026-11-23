%{
#include <stdio.h>
%}
%%
(0[1-9]|[12][0-9]|3[01])[-/](0[1-9]|1[0-2])[-/](19[0-9]{2}|20[0-9]{2}) { printf("DOB format valid: %s (calendar date not fully verified)\n",yytext); }
[^ \t\n]+ { printf("Invalid DOB format: %s\n",yytext); }
[ \t\n]+ ;
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
