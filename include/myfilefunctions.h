#ifndef MYFILEFUNCTIONS_H
#define MYFILEFUNCTIONS_H

#include <stdio.h>

// Count the number of lines, words and characters in the passed file
// Returns 0 on success and -1 on failure
int wordCount(FILE* file, int* lines, int* words, int* chars);

// Search lines containing search_str in a file, fills the matches array
// Returns the count of matches and -1 on failure
int mygrep(FILE* fp, const char* search_str, char*** matches);

#endif
