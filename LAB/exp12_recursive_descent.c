/* Experiment 12: Recursive descent parser for + and * expressions, parentheses and identifiers. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char s[256]; int p=0,ok=1;
void E(void); void T(void); void F(void);
void skip(void){ while(s[p]==' ') p++; }
void F(void){ skip(); if(s[p]=='('){ p++; E(); skip(); if(s[p]==')') p++; else ok=0; }
else if(isalpha((unsigned char)s[p])||s[p]=='_'){ while(isalnum((unsigned char)s[p])||s[p]=='_') p++; } else ok=0; }
void T(void){ F(); skip(); while(s[p]=='*'){ p++; F(); skip(); } }
void E(void){ T(); skip(); while(s[p]=='+'){ p++; T(); skip(); } }
int main(void){ printf("Enter expression: "); if(!fgets(s,sizeof s,stdin)) return 0; E(); skip(); puts(ok&&s[p]=='\n'?"Accepted":"Rejected"); return 0; }
