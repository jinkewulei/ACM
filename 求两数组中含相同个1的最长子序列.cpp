//������������A��B��ֻ����0,1 A��B������ȣ�������֪��������ֻ����0��1��
//����İ�����ͬ��Ŀ��1�������鳤�ȣ�Ҫ������λ��һ����
//��A[i]��A[j]������1�ĸ�����B[i]��B[j]������1�ĸ���һ����
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
	//������A��ȥ����B��������C�к�Ϊ0�����������Ϊ�����
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