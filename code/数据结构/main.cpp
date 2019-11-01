#include <iostream>
#include "DynamicArray/DynamicArray.h"
struct Person{
    char name[64];
    int age;
};
int main() {
    void** a = malloc(2*sizeof(void*));
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    a[0] = &p1;
    a[1] = &p2;
    printf("%s %d", ((struct Person*)a[1])->name, ((struct Person*)a[1])->age);
    return 0;
}