/* Experiment 13: Demonstration parser; assumed grammar E -> E+T | T, T -> T*F | F, F -> (E) | id.
   The supplied experiment list does not specify a grammar. */
#include <stdio.h>
#include <ctype.h>
char s[256]; int p=0,ok=1;
void E(void); void T(void); void F(void);
void ws(void){while(s[p]==' ')p++;}
void F(void){ws(); if(s[p]=='('){p++;E();ws();if(s[p]==')')p++;else ok=0;}
else if(isalpha((unsigned char)s[p])){while(isalnum((unsigned char)s[p]))p++;}else ok=0;}
void T(void){F();ws();while(s[p]=='*'){p++;F();ws();}}
void E(void){T();ws();while(s[p]=='+'){p++;T();ws();}}
int main(void){printf("Expression: ");if(!fgets(s,sizeof s,stdin))return 0;E();ws();puts(ok&&(s[p]=='\n'||s[p]=='\0')?"String satisfies grammar":"String does not satisfy grammar");return 0;}
