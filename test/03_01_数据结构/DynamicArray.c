#include "DynamicArray.h"

// 初始化函数
struct DynamicArray* init_DynamicArray(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}
	struct DynamicArray* myArr = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
	if (NULL == myArr) {	// 开辟内存不成功
		return NULL;
	}
	myArr->arrays = (void**)malloc(capacity * sizeof(void*));
	myArr->size = 0;
	myArr->capacity = capacity;
	return myArr;
}

// 遍历元素
void foreach_DynamicArray(struct DynamicArray* arr, void(*_callback)(void*)) {
	if (NULL == arr) {
		return;
	}
	if (NULL == _callback) {
		return;
	}
	int i;
	for (i = 0; i < arr->size; ++i) {
		_callback(arr->arrays[i]);
	}
}
// 插入元素
void insert_DynamicArray(struct DynamicArray* arr, int pos, void* data) {
	if (NULL == arr) {
		return;
	}
	if (pos < 0) {	// 如果为负数默认插在第一个位置
		pos = 0;
	}
	else if (pos > arr->size) {	// 如果大于最大位置默认插在最后
		pos = arr->size;	
	}
	if (arr->size >= arr->capacity) {	// 元素已经存满了
		void* newArr = realloc(arr->arrays, sizeof(void*) * arr->capacity * 2);	// 容量翻一倍
		memcpy(newArr, arr->arrays, sizeof(void*) * arr->size);
		arr->arrays = newArr;
		arr->capacity *= 2;
	}
	// 将pos后面的元素往后移动
	for (int i = arr->size - 1; i > pos; --i) {
		arr->arrays[i + 1] = arr->arrays[i];
	}
	arr->arrays[pos] = data;
}
// 删除元素(通过位置)
void remove_by_pos(struct DynamicArray* arr, int pos) {
	if (NULL == arr) {
		return;
	}
	if (pos<0 || pos>arr->size - 1) {
		return;
	}
	// 将pos后面的元素向前移动一个位置
	for ( int i = pos; i < arr->size-1; i++) {
		arr->arrays[i] = arr->arrays[i + 1];
	}
	arr->size--;
}
// 删除元素（通过值）
void remove_by_value(struct DynamicArray* arr, void* data, int(*compare)(void*, void*)) {
	if (NULL == arr) {
		return;
	}
	if (NULL == compare) {
		return;
	}
	for (int i = 0; i < arr->size; ++i) {		// 查找data
		if (compare(arr->arrays[i], data)) {	// 找到了
			for (int j = i; j < arr->size; ++j) {	// 将后面的元素前移
				arr->arrays[j] = arr->arrays[j + 1];
			}
			arr->arrays[arr->size - 1] = NULL;	// 删除最后元素的指针
			arr->size--;						// 修改大小
			break;
		}
	}
}
// 销毁函数
void delete_DynamicArray(struct DynamicArray* arr) {
	if (NULL == arr) {
		return;
	}
	free(arr->arrays);
	arr->arrays = NULL;
	free(arr);
	arr = NULL;
}

