//#include<iostream>
//using namespace std;
//const int MAX = 10;
//
//void RadixSortLSD(int *a, int arraySize)
//{
//	int i, bucket[MAX], maxVal = 0, digitPosition = 1;
//	for (i = 0; i < arraySize; i++) {
//		if (a[i] > maxVal) maxVal = a[i];
//	}
//
//	int pass = 1;  // used to show the progress
//	/* maxVal: this variable decide the while-loop count
//	if maxVal is 3 digits, then we loop through 3 times */
//	while (maxVal / digitPosition > 0) {
//		/* reset counter */
//		int digitCount[10] = { 0 };
//
//		/* count pos-th digits (keys)��λ�� */
//		for (i = 0; i < arraySize; i++)
//			digitCount[a[i] / digitPosition % 10]++;
//
//		/* accumulated count */
//		for (i = 1; i < 10; i++)
//			digitCount[i] += digitCount[i - 1];
//
//		/* To keep the order, start from back side */
//		for (i = arraySize - 1; i >= 0; i--)
//			bucket[--digitCount[a[i] / digitPosition % 10]] = a[i];
//
//		/* rearrange the original array using elements in the bucket */
//		for (i = 0; i < arraySize; i++)
//			a[i] = bucket[i];
//
//		/* at this point, a array is sorted by digitPosition-th digit */
//		
//
//		/* move up the digit position */
//		digitPosition *= 10;
//	}
//}

int maxbit(int data[], int n)
{
	int d = 1; //��������λ��  
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void radixsort(int data[], int n) //��������  
{
	int d = maxbit(data, n);
	//int tmp[n];
	int *tmp = new int[n];
	int count[10]; //������  
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������  ��ʮ��
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����  
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��  
			count[k]++;
		}

		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ  

		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��  
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}

		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��  
			data[j] = tmp[j];
		radix = radix * 10;
	}
}