#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//模板，比较器

void InsertSort(int arr[],size_t size)//O(N^2)
{
	for (size_t idx = 1; idx < size; ++idx)
	{
		int temp = arr[idx];
		int end = idx-1;
		while (end >= 0 && temp<arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = temp;
	}
}
//
void InsertSort_P(int arr[], size_t size)//
{

	for (size_t idx = 1; idx < size; ++idx)
	{
		int temp = arr[idx];
		int end = idx-1;
		int left = 0;
		int right = idx-1;
		int pos = 0;
		int mid = 0;
		while (left <= right)
		{
			mid = left + ((right - left) >> 1);
			if (temp < arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		for (pos = end; pos >= left; --pos)
			arr[pos + 1] = arr[pos];

		arr[left] = temp;
	}
}


void ShellSort(int arr[], size_t size)//O(N3 / 2)到O(N7 / 6)
{
	int gap = size;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (size_t idx = gap; idx < size; ++idx)
		{
			int temp = arr[idx];
			int end = idx - gap;
			while (end >= 0 && temp<arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = temp;
		}
	}
}


void PrintfArray(int *array,size_t size)
{
	for (size_t idx = 0; idx < size; ++idx)
	{
		cout << array[idx] << " ";
	}
	cout << endl;
}

void BubbleSort(int arr[],size_t size)
{
	bool flag = true;

	for (int i = 0; i < size && flag; ++i)
	{
		flag = false;
		for (int j = 0; j < size-i-1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
	}
}

void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (arr[j]<arr[i])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}



void HeapAdjust(int arr[], int root, int size)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child+1<size &&arr[child] < arr[child + 1])
			child += 1;
		if (arr[parent] < arr[child])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int arr[], size_t size)
{
	
		for (int idx = (size - 2) / 2; idx >= 0; --idx)
		{
			HeapAdjust(arr, idx, size);
		}

		int index = size - 1;
		while (index > 0)
		{
			std::swap(arr[0], arr[index]);
			HeapAdjust(arr, 0, index);
			index--;
		}
	
}

int partion(int arr[], int begin, int end)
{
	int key = arr[begin];
	while (begin < end)
	{
		
		while (begin<end && arr[end] >= key)
			end--;

		if (begin < end)
		{
			arr[begin] = arr[end];
			begin++;
		}

		while (begin<end&&arr[begin] <= key)
			begin++;

		if (begin < end)
		{
			arr[end] = arr[begin];
			end--;
		}
	}
	arr[begin] = key;
	return begin;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div - 1);
		QuickSort(arr, div + 1, right);
	}
}


int main()
{
	int arr[] = {0,5,1,2,4,3,6,8,9,7};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort_P(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);
	PrintfArray(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}