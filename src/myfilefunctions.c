#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Counts lines, words and characters in a file
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) return -1;  // return -1 if file doesn't exist

    *lines = 0;
    *words = 0;
    *chars = 0;

    int c;
    int in_word = 0;  // tracks if we are currently inside a word

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;                    // count every character

        if (c == '\n') (*lines)++;     // count newlines as lines

        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0;               // we left a word
        } else if (in_word == 0) {
            in_word = 1;               // we entered a new word
            (*words)++;
        }
    }

    return 0;  // success
}

// Searches for lines containing search_str in a file
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL) return -1;

    int count = 0;
    int capacity = 10;  // start with space for 10 matches
    char line[1024];    // buffer to hold each line

    // allocate initial array of string pointers
    *matches = malloc(capacity * sizeof(char*));
    if (*matches == NULL) return -1;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, search_str) != NULL) {  // if line contains search_str
            if (count == capacity) {              // grow array if full
                capacity *= 2;
                *matches = realloc(*matches, capacity * sizeof(char*));
            }
            (*matches)[count] = malloc(strlen(line) + 1);  // allocate space for this line
            strcpy((*matches)[count], line);                // copy line into array
            count++;
        }
    }

    return count;  // return number of matches found
}
