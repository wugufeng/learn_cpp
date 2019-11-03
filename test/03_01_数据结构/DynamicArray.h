#pragma once
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	struct DynamicArray {	// 动态数组
		void** arrays;			// 数组首地址，每个元素都是void*类型
		int size;			// 数组大小,实际保存的元素个数
		int capacity;		// 数组容量
	};

	// 初始化函数
	struct DynamicArray* init_DynamicArray(int capacity);
	// 遍历元素
	void foreach_DynamicArray(struct DynamicArray* arr, int(*_callback)(void*));
	// 插入元素
	void insert_DynamicArray(struct DynamicArray* arr, int pos, void* data);
	// 删除元素(通过位置)
	void remove_by_pos(struct DynamicArray* arr, int pos);
	// 删除元素（通过值）
	void remove_by_value(struct DynamicArray* arr, void* data, void(* compare)(void*));
	// 销毁函数
	void delete_DynamicArray(struct DynamicArray* arr);
#ifdef __cplusplus
}
#endif // 

