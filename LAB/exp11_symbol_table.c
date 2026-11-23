/* Experiment 11: Basic symbol table operations. */
#include <stdio.h>
#include <string.h>
#define N 50
struct Symbol { char name[32], type[16]; int address; } table[N];
int count=0;
int find(const char *name){ for(int i=0;i<count;i++) if(!strcmp(table[i].name,name)) return i; return -1; }
int main(void){
    int ch,addr; char name[32],type[16];
    do {
        printf("\n1.Insert 2.Search 3.Display 4.Delete 0.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){
            printf("Name Type Address: "); scanf("%31s %15s %d",name,type,&addr);
            if(find(name)>=0) puts("Symbol already exists.");
            else if(count<N){ strcpy(table[count].name,name); strcpy(table[count].type,type); table[count++].address=addr; puts("Inserted."); }
            else puts("Table full.");
        } else if(ch==2){ printf("Name: "); scanf("%31s",name); int k=find(name); if(k<0) puts("Not found."); else printf("%s %s %d\n",table[k].name,table[k].type,table[k].address); }
        else if(ch==3){ puts("NAME\tTYPE\tADDRESS"); for(int i=0;i<count;i++) printf("%s\t%s\t%d\n",table[i].name,table[i].type,table[i].address); }
        else if(ch==4){ printf("Name: "); scanf("%31s",name); int k=find(name); if(k<0) puts("Not found."); else { for(int i=k;i<count-1;i++) table[i]=table[i+1]; count--; puts("Deleted."); } }
    } while(ch!=0);
    return 0;
}
