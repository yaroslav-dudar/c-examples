#include "stdio.h"
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector_t *vector) {
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->size = 0;
    vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_increase_capacity(Vector_t *vector) {
    vector->capacity += VECTOR_INITIAL_CAPACITY;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

bool vector_is_full(Vector_t *vector) {
    return (vector->size == vector->capacity) ? true: false;
}

void vector_append(Vector_t *vector, int value) {
    if (vector_is_full(vector)) {
        vector_increase_capacity(vector);
    }

    vector->data[vector->size] = value;
    vector->size++;
    // or inline statement vector->data[vector->size++] = value;
}

int vector_get(Vector_t *vector, int index) {
    if (index + 1 > vector->size) {
        printf("Index out of range error.\n");
        exit(1);
    }
    return vector->data[index];
}

void vector_free(Vector_t *vector) {
    free(vector->data);
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
}
