#include "stdio.h"
#include "stdint.h"

int main() {
    // sizeof(int8_t) == 1 byte
    int8_t numbers[5] = {1,2,3,4,5};

    // The array variable holds the address
    // of the first element in the array
    printf("&numbers    = %p\n", (void *)&numbers);
    // &numbers[0] == numbers
    printf("numbers     = %p\n", (void *)numbers);
    // &numbers[0] == &numbers == numbers
    printf("&numbers[0] = %p\n", (void *)&numbers[0]);
    // &numbers[1] == &numbers[0] + 1byte
    printf("&numbers[1] = %p\n", (void *)&numbers[1]);
    // &numbers[2] == &numbers[1] + 1byte
    printf("&numbers[2] = %p\n", (void *)&numbers[2]);
    // &numbers[3] == &numbers[2] + 1byte
    printf("&numbers[3] = %p\n", (void *)&numbers[3]);
    // &numbers[4] == &numbers[3] + 1byte
    printf("&numbers[4] = %p\n", (void *)&numbers[4]);

    int8_t numbers2[5] = {6,7,8,9,10};
    //  Array variables cannot be changed
    // this won't compile

    //numbers = &numbers2;

    int8_t *ptr = numbers2;
    printf("ptr      = %p\n", (void *)ptr);
    // numbers2 == ptr
    printf("numbers2 = %p\n", (void *)numbers2);

    printf("*(ptr + 2)  = %d\n", *(ptr + 2));
    // *(ptr + 2) == numbers2[2]
    printf("numbers2[2] = %d\n", numbers2[2]);

    return 0;
};
