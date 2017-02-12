#include "stdio.h"
#include "string.h"
#include <stdlib.h>

// simple string wrapper
typedef struct {
    char* value;
} String_t;

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

int main() {
    String_t string1, string2;
    string1.value = "string_1";
    string2.value = "string_2";
    printf("string1.value=%s\n", string1.value);
    printf("string2.value=%s\n", string2.value);

    String_t string3 = concat(string1, string2);    
    printf("concat(string1, string2)=%s\n", string3.value);
    
    int string3_len = length(string3);
    printf("length(string3)=%d\n", string3_len);
    printf("string3.value=%s\n", string3.value);

    printf("find(string3, 't')=%d\n", find(string3, 't'));
    printf("find(string3, '2')=%d\n", find(string3, '2'));
    printf("find(string3, '3')=%d\n", find(string3, '3'));

    // TODO: find all occurrences in string of a given character
    // TODO: replace character
    // TODO: reverse a string
    // TODO: compare strings
    // TODO: get subset of a string
    // TODO: [int, float] to string
    return 0;
};
