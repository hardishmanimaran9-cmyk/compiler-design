/* Experiment 18: TRAILING sets for E->E+T|T, T->T*F|F, F->(E)|id. */
#include <stdio.h>
int main(void){
    puts("TRAILING(F) = { ), id }");
    puts("TRAILING(T) = { *, ), id }");
    puts("TRAILING(E) = { +, *, ), id }");
    return 0;
}
