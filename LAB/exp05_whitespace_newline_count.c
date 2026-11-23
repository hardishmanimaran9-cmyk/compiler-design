/* Experiment 5: Count spaces, tabs and newline characters from input. */
#include <stdio.h>
int main(void) {
    int c, spaces=0,tabs=0,newlines=0;
    puts("Enter text (Ctrl+D on Linux / Ctrl+Z then Enter on Windows to finish):");
    while((c=getchar())!=EOF) { if(c==' ') spaces++; else if(c=='\t') tabs++; else if(c=='\n') newlines++; }
    printf("Spaces: %d\nTabs: %d\nNewlines: %d\n",spaces,tabs,newlines);
    return 0;
}
