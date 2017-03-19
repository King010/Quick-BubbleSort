#include<iostream>
#include<stack>
using namespace std;

void BubbleSort(int arr[], size_t size)//Ã°ÅÝÅÅÐò(¸Ä½ø°æ)
{
	bool flag = true;

	for (int i = 0; i < size && flag; ++i)
	{
		flag = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
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

int partion1(int *arr, int left, int right)
{
	int Cur = left;
	int prev = Cur - 1;
	int key = arr[right];
	while (Cur <= right)
	{
		if (arr[Cur] <= key && ++prev == Cur - 1)
			std::swap(arr[Cur], arr[prev]);
		++Cur;
	}
	return prev;

}

int partion2(int array[], int left, int right)
{
	int begin = left;
	int end = right-1;

	int key = array[right];

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] > key)
			end--;

		if (begin < end)
		{
			swap(array[begin], array[end]);
			begin++;
			//end--;
		}
	}
	if (begin != right && array[begin] > array[right])
	{
		swap(array[begin], array[right]);
		return begin;
	}
	return right;
}


void QuickSortNor(int *arr, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();
		if (left < right)
		{
			int div = partion(arr, left, right);
			s.push(right);
			s.push(div + 1);
			s.push(div - 1);
			s.push(left);
		}
	}
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int div = partion2(arr, left, right);
		QuickSort(arr, left, div - 1);
		QuickSort(arr, div + 1, right);
	}
}