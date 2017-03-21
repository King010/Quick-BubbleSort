#include<iostream>
using namespace std;


void SelectSort(int arr[], int size)//—°‘Ò≈≈–Ú
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
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
		if (child + 1<size &&arr[child] < arr[child + 1])
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