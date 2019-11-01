#include"DynamicArray.h"

//��ʼ������
struct DynamicArray *Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	arr->capacity = capacity;
	arr->addr = malloc(sizeof(void *)*arr->capacity);
	arr->size = 0;

	return arr;
}
//����Ԫ��
int Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data) {
    // int���Ϳ��Ա���Ƿ����ɹ���0��ʾ�ɹ���-1��ʾʧ��

	if (NULL == arr)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -1;
	}

	if (pos < 0 || pos > arr->size)
	{
		pos = arr->size;
	}

	//�жϿռ��Ƿ��㹻
	if (arr->size >= arr->capacity)
	{

		//1. ����һ�������ڴ�ռ�
		int newcapacity = arr->capacity * 2;
		void **newspace = malloc(sizeof(void *)* newcapacity);

		if(NULL == newspace) {  // ���ٿռ�ʧ��
		    return -1;
		}
		//2. ��ԭ���ռ�����ݿ������¿ռ�
		memcpy(newspace, arr->addr, sizeof(void *)* arr->capacity);

		//3. �ͷ�ԭ���ռ���ڴ�
		free(arr->addr);

		//4. ����addrָ��
		arr->addr = newspace;
		arr->capacity = newcapacity;

	}


	//�ƶ�Ԫ�أ���posλ�ÿճ�λ����
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}

	//����Ԫ�ز��뵽posλ��
	arr->addr[pos] = data;
	arr->size++;
	return 0;
}
//����
void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == _callback)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}


}

//λ��ɾ��
void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos)
{

	if (NULL == arr)
	{
		return;
	}

	if (pos < 0 || pos > arr->size - 1)
	{
		return;
	}


	for (int i = pos; i < arr->size - 1; ++i)
	{
		arr->addr[i] = arr->addr[i + 1];
	}


	arr->size--;
}

//��ֵɾ��
void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void*, void *))
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (NULL == compare)
	{
		return;
	}


	for (int i = 0; i < arr->size; ++i)
	{
		if (compare(arr->addr[i], data))
		{
			RemoveByPos_DynamicArray(arr, i);
			break;
		}
	}

}

//��������
void Destroy_DynamicArray(struct DynamicArray *arr)
{
	if (NULL == arr)
	{
		return;
	}

	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}

	free(arr);
	arr = NULL;
}
