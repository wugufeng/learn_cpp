#pragma once
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	struct DynamicArray {	// ��̬����
		void** arrays;			// �����׵�ַ��ÿ��Ԫ�ض���void*����
		int size;			// �����С,ʵ�ʱ����Ԫ�ظ���
		int capacity;		// ��������
	};

	// ��ʼ������
	struct DynamicArray* init_DynamicArray(int capacity);
	// ����Ԫ��
	void foreach_DynamicArray(struct DynamicArray* arr, int(*_callback)(void*));
	// ����Ԫ��
	void insert_DynamicArray(struct DynamicArray* arr, int pos, void* data);
	// ɾ��Ԫ��(ͨ��λ��)
	void remove_by_pos(struct DynamicArray* arr, int pos);
	// ɾ��Ԫ�أ�ͨ��ֵ��
	void remove_by_value(struct DynamicArray* arr, void* data, void(* compare)(void*));
	// ���ٺ���
	void delete_DynamicArray(struct DynamicArray* arr);
#ifdef __cplusplus
}
#endif // 

