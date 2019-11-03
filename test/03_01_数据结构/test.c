#include "DynamicArray.h"
#include <stdio.h>

struct Person
{
	char name[64];
	int age;
};

void callback (void* data) {
	struct Person* d = (struct Person*) data;
	printf("name = %s ; age = %d\n", d->name, d->age);
}

void test() {
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 10 };
	struct Person p3 = { "ccc", 10 };
	struct Person p4 = { "ddd", 10 };
	struct Person p5 = { "eee", 10 };
	struct Person p6 = { "fff", 10 };

	struct DynamicArray* da = init_DynamicArray(5);	// ≥ı ºªØ
	printf("capacity = %d", da->capacity);
	insert_DynamicArray(da, 0, &p1);	// ≤Â»Î
	insert_DynamicArray(da, 1, &p2);
	insert_DynamicArray(da, 2, &p3);
	insert_DynamicArray(da, 2, &p4);
	insert_DynamicArray(da, 2, &p5);
//	insert_DynamicArray(da, 5, &p6);

//	foreach_DynamicArray(da, callback);
	
}

int main()
{
	test();
	return 0;
}