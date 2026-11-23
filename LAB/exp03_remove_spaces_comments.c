/* Experiment 3: Remove whitespace and C comments from one input line. */
#include <stdio.h>
int main(void) {
    char s[2000]; int i=0, space=0;
    puts("Enter one line of source code:");
    if(!fgets(s,sizeof s,stdin)) return 0;
    while(s[i]) {
        if(s[i]=='/' && s[i+1]=='/') break;
        if(s[i]=='/' && s[i+1]=='*') { i+=2; while(s[i] && !(s[i]=='*'&&s[i+1]=='/')) i++; if(s[i]) i+=2; continue; }
        if(s[i]==' '||s[i]=='\t'||s[i]=='\n'||s[i]=='\r') { space=1; i++; continue; }
        if(space) { putchar(' '); space=0; }
        putchar(s[i++]);
    }
    putchar('\n'); return 0;
}
