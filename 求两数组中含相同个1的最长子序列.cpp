//给定两个数组A和B，只包含0,1 A和B长度相等，并且已知其中所有只包含0和1。
//求最长的包含相同数目的1的子数组长度，要求索引位置一样。
//即A[i]到A[j]包含的1的个数和B[i]到B[j]包含的1的个数一样。
#include <iostream>
using namespace std;

int calLength(int arr[], int length, int *index)
{
	int sum = 0;
	int max = 0;
	//int curr = 0;
	
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += arr[k];
			}
			if ((sum == 0) && ((j-i+1) > max))
			{
				max = j-i+1;
				*index = i;
			}
		}
	}
	
	return max;
}

int main()
{
	//用数组A减去数组B，则数组C中和为0的最长子序列则为所求解
	int A[] = {0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1};
	int B[] = {1,1,0,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0};
	
	int arrLen = sizeof(A) / sizeof(int);
	int *C = new int[arrLen];
	int index = 0;

	for (int i = 0; i < arrLen; i++)
	{
		C[i] = A[i] - B[i];
		cout<<C[i]<<" ";
	}
	cout<<calLength(C,arrLen,&index)<<endl;
	cout<<"Index: "<<index<<endl;

	getchar();
	return 0;
}