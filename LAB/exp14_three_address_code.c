/* Experiment 14: Generate simple three-address code for a+b*c style expressions.
   Handles single-character operands and +,-,*,/ with * and / precedence. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char s[200],op[200]; int top=0,temp=1;
int prec(char c){return c=='*'||c=='/'?2:(c=='+'||c=='-'?1:0);}
void emit(char a,char b,char o){printf("t%d = %c %c %c\n",temp,a,o,b); s[0]=s[0];}
int main(void){
    char out[200][32]; int n=0; char vals[200][32]; int vn=0;
    printf("Enter expression (single-letter/digit operands): "); if(!fgets(s,sizeof s,stdin))return 0;
    for(int i=0;s[i]&&s[i]!='\n';){
        if(isspace((unsigned char)s[i])){i++;continue;}
        if(isalnum((unsigned char)s[i])){vals[vn][0]=s[i++];vals[vn++][1]='\0';}
        else if(strchr("+-*/()",s[i])){
            char c=s[i++];
            if(c=='(')op[top++]=c;
            else if(c==')'){while(top&&op[top-1]!='(')out[n++][0]=op[--top];if(top)top--;}
            else {while(top&&prec(op[top-1])>=prec(c))out[n++][0]=op[--top];op[top++]=c;}
        } else {puts("Invalid character.");return 0;}
    }
    while(top)out[n++][0]=op[--top];
    char stack[200][32];int sp=0,t=1;
    for(int i=0;i<n;i++){
        char c=out[i][0];
        if(isalnum((unsigned char)c)){stack[sp][0]=c;stack[sp++][1]=0;}
        else {if(sp<2){puts("Invalid expression.");return 0;} char b[32],a[32];strcpy(b,stack[--sp]);strcpy(a,stack[--sp]);printf("t%d = %s %c %s\n",t,a,c,b);sprintf(stack[sp++],"t%d",t++);}
    }
    if(sp==1)printf("Result: %s\n",stack[0]);else puts("Invalid expression.");
    return 0;
}
