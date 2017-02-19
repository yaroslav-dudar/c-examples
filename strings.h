#include "vector.h"

// simple string wrapper
typedef struct {
    char* value;
} String_t;

// string public interface definition
String_t concat(String_t str_1, String_t str_2);
int length(String_t str);
int find(String_t str, const char to_find);
Vector_t* find_all(String_t str, const char to_find);
