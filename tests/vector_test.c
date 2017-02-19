#include "stdio.h"
#include <stdlib.h>
#include "../vector.h"

int main() {
    Vector_t *vector = malloc(sizeof(Vector_t));
    vector_init(vector);

    vector_append(vector, 15);
    vector_append(vector, 5);
    vector_append(vector, 10);

    printf("%d\n", vector->size); // 3
    printf("%d\n", vector->capacity); // 100

    int i;
    for (i=0; i<vector->size; i++) {
        printf("vector[%d] = %d\n", i, vector_get(vector, 0));
    }

    // error here vector_get(vector,3);

    for (i=0; i<250; i++) {
        vector_append(vector, i*2);
    }

    printf("%d\n", vector->size); // 253
    printf("%d\n", vector->capacity); // 300
    printf("%d\n", vector_get(vector, 252)); // 498

    vector_free(vector);
    printf("%d\n", vector->size); // 0

    return 0;
}
