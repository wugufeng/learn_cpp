#include "DynamicArray.h"

// ��ʼ������
struct DynamicArray* init_DynamicArray(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}
	struct DynamicArray* myArr = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
	if (NULL == myArr) {	// �����ڴ治�ɹ�
		return NULL;
	}
	myArr->arrays = (void**)malloc(capacity * sizeof(void*));
	myArr->size = 0;
	myArr->capacity = capacity;
	return myArr;
}

// ����Ԫ��
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
// ����Ԫ��
void insert_DynamicArray(struct DynamicArray* arr, int pos, void* data) {
	if (NULL == arr) {
		return;
	}
	if (pos < 0) {	// ���Ϊ����Ĭ�ϲ��ڵ�һ��λ��
		pos = 0;
	}
	else if (pos > arr->size) {	// ����������λ��Ĭ�ϲ������
		pos = arr->size;	
	}
	if (arr->size >= arr->capacity) {	// Ԫ���Ѿ�������
		void* newArr = realloc(arr->arrays, sizeof(void*) * arr->capacity * 2);	// ������һ��
		memcpy(newArr, arr->arrays, sizeof(void*) * arr->size);
		arr->arrays = newArr;
		arr->capacity *= 2;
	}
	// ��pos�����Ԫ�������ƶ�
	for (int i = arr->size - 1; i > pos; --i) {
		arr->arrays[i + 1] = arr->arrays[i];
	}
	arr->arrays[pos] = data;
}
// ɾ��Ԫ��(ͨ��λ��)
void remove_by_pos(struct DynamicArray* arr, int pos) {
	if (NULL == arr) {
		return;
	}
	if (pos<0 || pos>arr->size - 1) {
		return;
	}
	// ��pos�����Ԫ����ǰ�ƶ�һ��λ��
	for ( int i = pos; i < arr->size-1; i++) {
		arr->arrays[i] = arr->arrays[i + 1];
	}
	arr->size--;
}
// ɾ��Ԫ�أ�ͨ��ֵ��
void remove_by_value(struct DynamicArray* arr, void* data, int(*compare)(void*, void*)) {
	if (NULL == arr) {
		return;
	}
	if (NULL == compare) {
		return;
	}
	for (int i = 0; i < arr->size; ++i) {		// ����data
		if (compare(arr->arrays[i], data)) {	// �ҵ���
			for (int j = i; j < arr->size; ++j) {	// �������Ԫ��ǰ��
				arr->arrays[j] = arr->arrays[j + 1];
			}
			arr->arrays[arr->size - 1] = NULL;	// ɾ�����Ԫ�ص�ָ��
			arr->size--;						// �޸Ĵ�С
			break;
		}
	}
}
// ���ٺ���
void delete_DynamicArray(struct DynamicArray* arr) {
	if (NULL == arr) {
		return;
	}
	free(arr->arrays);
	arr->arrays = NULL;
	free(arr);
	arr = NULL;
}

