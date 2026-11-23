/* Experiment 9: Eliminate immediate left recursion: L -> L,S | S. */
#include <stdio.h>
int main(void) {
    puts("Original grammar:");
    puts("S -> (L) | a");
    puts("L -> L , S | S");
    puts("\nGrammar after eliminating left recursion:");
    puts("S  -> (L) | a");
    puts("L  -> S L'");
    puts("L' -> , S L' | epsilon");
    return 0;
}
