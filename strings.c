#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "strings.h"

String_t concat(String_t str_1, String_t str_2) {
    // It concatenates two strings and returns the combined one string.
    String_t newString;
    int newSize = strlen(str_1.value) + strlen(str_2.value) + 1;
    newString.value = (char *)malloc(newSize);

    // Copies the string pointed to str_1 to newString.
    strcpy(newString.value, str_1.value);
    // Appends the string pointed to by str_2
    // to the end of the string pointed to by newString.
    strcat(newString.value, str_2.value);
    return newString;
}

int length(String_t str) {
    // Calculate string length without stop symbol
    //return strlen(str.value)
    int len = 0;
    while (*str.value != '\0') {
        len++; str.value++;
    }
    return len;
}

int find(String_t str, const char to_find) {
    // Find first occurrence of character to_find in str
    // If there no given character return -1
    int index = 0;
    while (*str.value != '\0') {
        if (*str.value == to_find) {
            return index;
        }
        index++; str.value++;
    }
    return -1;
}

Vector_t* find_all(String_t str, const char to_find) {
    // Find all occurrences in string of a given character
    // and return their positions
    Vector_t *res_vector = malloc(sizeof(Vector_t));
    vector_init(res_vector);

    int index = 0;
    while (*str.value != '\0') {
        if (*str.value == to_find) {
           vector_append(res_vector, index);
        }
        index++; str.value++;
    }

    return res_vector;
}

// TODO: replace character
// TODO: reverse a string
// TODO: compare strings
// TODO: get subset of a string
// TODO: [int, float] to string
