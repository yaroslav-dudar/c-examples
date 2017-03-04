#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#include "../strings.h"

int main() {
    String_t string1 = string_init("string_1");
    String_t string2 = string_init("string_2");
    printf("string1.value=%s\n", string_get(string1));
    printf("string2.value=%s\n", string_get(string2));

    String_t string3 = string_concat(string1, string2);
    printf("concat(string1, string2)=%s\n", string_get(string3));
    
    int string3_len = string_length(string3);
    printf("length(string3)=%d\n", string3_len);
    printf("string3.value=%s\n", string_get(string3));

    printf("find(string3, 't')=%d\n", string_find(string3, 't'));
    printf("find(string3, '2')=%d\n", string_find(string3, '2'));
    printf("find(string3, '3')=%d\n", string_find(string3, '3'));

    String_t* str_ptr = &string1;
    string_replace(str_ptr, 's', 'f');
    printf("replace(str_ptr, 's', 'f')=%s\n", string_get(*str_ptr));
    string_replace(str_ptr, 'f', 's');
    printf("replace(str_ptr, 'f', 's')=%s\n", string_get(*str_ptr));

    string_reverse(str_ptr);
    printf("string_reverse(str_ptr)=%s\n", string_get(*str_ptr));

    printf("string_cmp(string1, string2)=%d\n", string_cmp(string1, string2));
    printf("string_cmp(string1, *str_ptr)=%d\n", string_cmp(string1, *str_ptr));

    Vector_t *all_i_chars = string_find_all(string3, 'i');
    int i;
    for (i=0; i<all_i_chars->size; i++) {
        printf("%d\n", vector_get(all_i_chars, i));
    }
    free(all_i_chars);

    return 0;
};
