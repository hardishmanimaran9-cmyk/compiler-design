/* Experiment 10: Left factoring S -> iEtS | iEtSeS | a; E -> b. */
#include <stdio.h>
int main(void) {
    puts("Original: S -> iEtS | iEtSeS | a; E -> b");
    puts("Left-factored grammar:");
    puts("S  -> iEtS S' | a");
    puts("S' -> eS | epsilon");
    puts("E  -> b");
    return 0;
}
