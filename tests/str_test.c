#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#include "../strings.h"

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

    Vector_t *all_i_chars = find_all(string3, 'i');
    int i;
    for (i=0; i<all_i_chars->size; i++) {
        printf("%d\n", vector_get(all_i_chars, i));
    }
    free(all_i_chars);

    return 0;
};
