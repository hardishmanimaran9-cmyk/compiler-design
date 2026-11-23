/* Experiment 15: Count characters, words and lines in a file. */
#include <stdio.h>
#include <ctype.h>
int main(int argc,char **argv){
    FILE *f; int c,inword=0; long chars=0,words=0,lines=0;
    if(argc<2){printf("Usage: %s filename\n",argv[0]);return 1;}
    f=fopen(argv[1],"r");if(!f){perror("File");return 1;}
    while((c=fgetc(f))!=EOF){chars++;if(c=='\n')lines++;if(isspace(c))inword=0;else if(!inword){words++;inword=1;}}
    fclose(f);printf("Characters: %ld\nWords: %ld\nLines: %ld\n",chars,words,lines);return 0;
}
