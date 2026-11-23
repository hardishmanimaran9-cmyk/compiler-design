/* Experiment 6: Validate a C identifier (letters/digits/underscore; not starting with digit). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char s[256]; int i,ok=1;
    printf("Enter identifier: "); if(scanf("%255s",s)!=1) return 0;
    if(!(isalpha((unsigned char)s[0])||s[0]=='_')) ok=0;
    for(i=1;s[i];i++) if(!(isalnum((unsigned char)s[i])||s[i]=='_')) ok=0;
    printf("%s\n",ok?"Valid identifier":"Invalid identifier"); return 0;
}
