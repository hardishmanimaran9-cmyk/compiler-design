%{
#include <stdio.h>
%}
%%
[0-9]+[ \t]*[+*/-][ \t]*[0-9]+ {
    int a,b; char op; sscanf(yytext,"%d %c %d",&a,&op,&b);
    if(op=='+') printf("%d\n",a+b);
    else if(op=='-') printf("%d\n",a-b);
    else if(op=='*') printf("%d\n",a*b);
    else if(op=='/') { if(b) printf("%g\n",(double)a/b); else puts("Division by zero"); }
}
[ \t\n]+ ;
. { printf("Invalid input: %s\n",yytext); }
%%
int main(void){yylex();return 0;}
int yywrap(void){return 1;}
