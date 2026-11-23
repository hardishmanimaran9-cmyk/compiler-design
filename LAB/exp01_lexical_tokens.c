/* Experiment 1: Identify identifiers, constants and operators; ignore whitespace/comments. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char s[2000]; int i=0;
    printf("Enter a C-like statement:\n");
    if (!fgets(s,sizeof s,stdin)) return 0;
    while (s[i]) {
        if (isspace((unsigned char)s[i])) { i++; continue; }
        if (s[i]=='/' && s[i+1]=='/') break;
        if (s[i]=='/' && s[i+1]=='*') { i+=2; while(s[i] && !(s[i]=='*'&&s[i+1]=='/')) i++; if(s[i]) i+=2; continue; }
        if (isalpha((unsigned char)s[i]) || s[i]=='_') {
            int j=i; while(isalnum((unsigned char)s[i])||s[i]=='_') i++;
            printf("IDENTIFIER: %.*s\n",i-j,s+j);
        } else if (isdigit((unsigned char)s[i])) {
            int j=i; while(isdigit((unsigned char)s[i])||s[i]=='.') i++;
            printf("CONSTANT: %.*s\n",i-j,s+j);
        } else {
            if (strchr("+-*/%=<>!&|",s[i])) printf("OPERATOR: %c\n",s[i]);
            else printf("SPECIAL: %c\n",s[i]);
            i++;
        }
    }
    return 0;
}
