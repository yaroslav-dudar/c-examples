#include "vector.h"

typedef int bool;
#define true 1
#define false 0

// simple string wrapper
typedef struct {
    char* value;
} String_t;

// string public interface definition
String_t string_init(const char * str);
char * string_get(String_t str);
String_t string_concat(String_t str_1, String_t str_2);
int string_length(String_t str);
int string_find(String_t str, const char to_find);
Vector_t* string_find_all(String_t str, const char to_find);
void string_replace(String_t* str, const char from,  const char to);
void string_reverse(String_t * str);
bool string_cmp(String_t str_1, String_t str_2);
