#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "strings.h"

String_t string_init(const char * str) {
    String_t newString;
    int strSize = strlen(str) + 1;

    newString.value = malloc(strSize * sizeof(char));
    strcpy(newString.value, str);
    return newString;
}

char * string_get(String_t str) {
    return str.value;
}

String_t string_concat(String_t str_1, String_t str_2) {
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

int string_length(String_t str) {
    // Calculate string length without stop symbol
    //return strlen(str.value)
    int len = 0;
    while (*str.value != '\0') {
        len++; str.value++;
    }
    return len;
}

int string_find(String_t str, const char to_find) {
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

Vector_t* string_find_all(String_t str, const char to_find) {
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

void string_replace(String_t* str, const char from,  const char to) {
    // replace all "from"" chars to the "to" chars
    int index = 0;
    while (str->value[index] != '\0') {
        if (str->value[index] == from) {
            str->value[index] = to;
        }
        index++;
    }
}

void string_reverse(String_t* str) {
    int i;
    char *begin, *end, temp;
    int str_len = string_length(*str);

    begin  = str->value;
    end    = str->value;

    for (i = 0; i < str_len - 1; i++) {
        // move end pointer to the end of str
        end++;
    }

    for (i = 0; i < str_len/2; i++) {
        temp   = *end;
        *end   = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}

bool string_cmp(String_t str_1, String_t str_2) {
    // check if str_1 equal to the str_2
    if (string_length(str_1) != string_length(str_2)) {
        return false;
    }

    int i = 0;
    while (str_1.value[i] != '\0') {
        if (str_1.value[i] != str_2.value[i]) {
            return false;
        }
        i++;
    }
    return true;
}

// TODO: get subset of a string
// TODO: [int, float] to string
