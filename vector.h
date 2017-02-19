#define VECTOR_INITIAL_CAPACITY 100

typedef int bool;
#define true 1
#define false 0

// dynamic array of int values
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector_t;

// vector public interface definition
void vector_init(Vector_t *vector);
void vector_increase_capacity(Vector_t *vector);
bool vector_is_full(Vector_t *vector);
void vector_append(Vector_t *vector, int value);
void vector_free(Vector_t *vector);
int vector_get(Vector_t *vector, int index);
