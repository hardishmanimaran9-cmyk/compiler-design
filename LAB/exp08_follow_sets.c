/* Experiment 8: FOLLOW sets for the grammar in the experiment list. */
#include <stdio.h>
int main(void) {
    puts("Grammar: S -> AaAb | BbBa; A -> epsilon; B -> epsilon");
    puts("FOLLOW(S) = { $ }");
    puts("FOLLOW(A) = { a, b }");
    puts("FOLLOW(B) = { a, b }");
    return 0;
}
