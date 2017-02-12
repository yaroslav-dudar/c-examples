#include "stdio.h"
#include "stdint.h"

// function prototype
void sayHello(int argument);
int add(int x, int y);
int domath(int (*math_func)(int, int), int x, int y);

// function implementation
void sayHello(int argument) {
    printf("hello world\n");
}

int add(int x, int y) {
    return x + y;
}
int domath(int (*math_func)(int, int), int x, int y) {
    return (*math_func)(x, y);
}

int main() {
    void * ptr = sayHello;
    void (*sayHelloPtr)(int) = sayHello;
    printf("sayHello     = %p\n", sayHello);
    // ptr == sayHello
    printf("ptr          = %p\n", ptr);
    // sayHelloPtr == sayHello
    printf("sayHelloPtr  = %p\n", sayHelloPtr);
    // sayHelloPtr == *sayHelloPtr
    printf("*sayHelloPtr = %p\n", (*sayHelloPtr));
    // *sayHelloPtr == **sayHelloPtr
    printf("*sayHelloPtr = %p\n", (**sayHelloPtr));
    // *sayHelloPtr == ***sayHelloPtr
    printf("*sayHelloPtr = %p\n", (***sayHelloPtr));

    (*sayHelloPtr)(10); // print hello world
    // this won't compile
    // called object is not a function or function pointer
    //(*ptr)(10);

    // pass function to another function as a pointer
    int a = domath(add, 10, 2);
    printf("domath      = %d\n", a);

    return 0;
};
