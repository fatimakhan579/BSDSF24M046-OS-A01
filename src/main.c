#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    // ---- Testing String Functions ----
    printf("--- Testing String Functions ---\n");

    // test mystrlen
    char* str = "Hello World";
    printf("mystrlen('%s') = %d\n", str, mystrlen(str));

    // test mystrcpy
    char dest[50];
    mystrcpy(dest, str);
    printf("mystrcpy result: %s\n", dest);

    // test mystrncpy
    char dest2[50];
    mystrncpy(dest2, str, 5);
    printf("mystrncpy (first 5 chars): %s\n", dest2);

    // test mystrcat
    char dest3[50];
    mystrcpy(dest3, "Hello");
    mystrcat(dest3, " World");
    printf("mystrcat result: %s\n", dest3);

    // ---- Testing File Functions ----
    printf("\n--- Testing File Functions ---\n");

    // create a small test file
    FILE* f = fopen("testfile.txt", "w");
    fprintf(f, "Hello World\n");
    fprintf(f, "This is a test file\n");
    fprintf(f, "Hello again\n");
    fclose(f);

    // test wordCount
    FILE* f2 = fopen("testfile.txt", "r");
    int lines, words, chars;
    wordCount(f2, &lines, &words, &chars);
    fclose(f2);
    printf("wordCount -> lines: %d, words: %d, chars: %d\n", lines, words, chars);

    // test mygrep
    FILE* f3 = fopen("testfile.txt", "r");
    char** matches;
    int count = mygrep(f3, "Hello", &matches);
    fclose(f3);
    printf("mygrep found %d lines containing 'Hello':\n", count);
    for (int i = 0; i < count; i++) {
        printf("  %s", matches[i]);
        free(matches[i]);  // free each line
    }
    free(matches);  // free the array itself

    return 0;
}
