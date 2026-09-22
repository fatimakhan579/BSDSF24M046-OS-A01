#include "../include/mystrfunctions.h"

// Returns the length of string s (counts characters until null terminator)
int mystrlen(const char* s) {
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}

// Copies string src into dest, returns number of characters copied
int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // add null terminator at end
    return i;
}

// Copies at most n characters from src to dest
int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // add null terminator
    return i;
}

// Appends src to the end of dest, returns new total length
int mystrcat(char* dest, const char* src) {
    int dest_len = mystrlen(dest);  // find where dest ends
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];  // start copying after dest ends
        i++;
    }
    dest[dest_len + i] = '\0';  // null terminate
    return dest_len + i;
}
