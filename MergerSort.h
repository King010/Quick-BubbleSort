#include<string.h>
void Merge(int *arr, int *temp, int left, int mid, int right)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}
	while (begin1 <= end1)
		temp[index++] = arr[begin1++];
	while (begin2 <= end2)
		temp[index++] = arr[begin2++];

}

void _MergerSort(int *arr, int *temp, int left, int right)
{
	if (left < right)
	{
		int mid = left + ((right - left) >> 1);
		_MergerSort(arr, temp,left, mid);
		_MergerSort(arr, temp, mid+1,right);
		Merge(arr, temp, left, mid, right);
		memcpy(arr + left, temp + left, sizeof(arr[0])*(right - left + 1));
	}
}

void MergeSort(int *arr, int size)
{
	int *temp = new int[size];
	_MergerSort(arr, temp, 0, size - 1);
	delete[]temp;
}


void MergeSortNor(int *arr, int size)
{
	int *temp = new int[size];
	int left = 0;
	int right = size - 1;
	int gap = 1;
	while (gap < size)
	{
		for (int idx = 0; idx < size; idx += gap*2)
		{
			left = idx;
			int mid = left + gap - 1;
			int right = mid+gap;
			if (mid >= size)
				mid = size - 1;
			if (right >= size)
				right = size - 1;
			Merge(arr, temp, left, mid, right);
		}
		memcpy(arr, temp, size*sizeof(arr[0]));
		gap <<= 1;
	}
	delete[]temp;
}