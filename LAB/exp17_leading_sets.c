/* Experiment 17: LEADING sets for E->E+T|T, T->T*F|F, F->(E)|id. */
#include <stdio.h>
int main(void){
    puts("LEADING(F) = { (, id }");
    puts("LEADING(T) = { *, (, id }");
    puts("LEADING(E) = { +, *, (, id }");
    return 0;
}
