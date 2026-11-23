/* Experiment 4: Recognize arithmetic operators + - * /. */
#include <stdio.h>
int main(void) {
    char s[500]; int i;
    printf("Enter an expression: "); if(!fgets(s,sizeof s,stdin)) return 0;
    for(i=0;s[i];i++) if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        printf("%c : valid arithmetic operator\n",s[i]);
    return 0;
}
