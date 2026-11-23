/* Experiment 2: Check whether the entered line is a C comment. */
#include <stdio.h>
#include <string.h>
int main(void) {
    char s[1000]; int n;
    printf("Enter a line: "); if(!fgets(s,sizeof s,stdin)) return 0;
    n=(int)strlen(s);
    while(n && (s[n-1]=='\n'||s[n-1]=='\r')) s[--n]='\0';
    if ((n>=2 && s[0]=='/' && s[1]=='/') ||
        (n>=4 && s[0]=='/' && s[1]=='*' && s[n-2]=='*' && s[n-1]=='/'))
        puts("It is a comment.");
    else puts("It is not a complete comment.");
    return 0;
}
