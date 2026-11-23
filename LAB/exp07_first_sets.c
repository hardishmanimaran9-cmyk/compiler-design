/* Experiment 7: FIRST sets for S -> AaAb | BbBa, A -> epsilon, B -> epsilon. */
#include <stdio.h>
int main(void) {
    puts("Grammar: S -> A a A b | B b B a; A -> epsilon; B -> epsilon");
    puts("FIRST(A) = { epsilon }");
    puts("FIRST(B) = { epsilon }");
    puts("FIRST(AaAb) = { a }");
    puts("FIRST(BbBa) = { b }");
    puts("FIRST(S) = { a, b }");
    return 0;
}
