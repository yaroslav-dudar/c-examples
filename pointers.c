#include "stdio.h"

int main() {
    int var = 10;
    int *ptr = &var;

    printf("sizeof(ptr)- %ld\n", sizeof(ptr));
    printf("sizeof(&ptr)- %ld\n", sizeof(&ptr));
    printf("sizeof(&var)- %ld\n", sizeof(&var));
    printf("sizeof(var)- %ld\n", sizeof(var));

    printf("ptr- %p\n", (void *)ptr);
    printf("&ptr-%p\n", (void *)&ptr);
    printf("&var-%p\n", (void *)&var);

    return 0;
}
