/* Experiment 16: Demonstration compiler backend translating simple TAC to pseudo assembly.
   Input lines: t1 = a + b ; supported operators + - * /. */
#include <stdio.h>
int main(void){
    char lhs[32],a[32],b[32],op;
    puts("Enter TAC lines (one per line; EOF to finish):");
    while(scanf("%31s = %31s %c %31s",lhs,a,&op,b)==4){
        printf("LOAD R1, %s\n",a);
        printf("LOAD R2, %s\n",b);
        switch(op){case '+':puts("ADD R1, R2");break;case '-':puts("SUB R1, R2");break;case '*':puts("MUL R1, R2");break;case '/':puts("DIV R1, R2");break;default:puts("; unsupported operator");}
        printf("STORE %s, R1\n",lhs);
    }
    return 0;
}
