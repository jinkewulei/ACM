#include <iostream>
using namespace std;

//�㷨���Ӷ�O(n)
//˼�룺��ͷɨ������飬ֻҪ��m-n��ļ�Ȩ����0
//��ô���m-n��Ե�n+1�������������ģ����������һ��
//�����m-n��С��0�ˣ���ô�����������ȥ�϶��Ժ�����˥������������m
//ÿһ����ӵĽ�������maxVal�Ƚϣ�����maxVal���ܴ洢���ֵ
int maxSum(int a[], int length)
{
	int sum = 0;
	int maxVal = 0;
	
	for (int i = 0;i < length;i++)
	{
		if (sum<0)
		{
			sum = a[i];
		}
		else
		{
			sum += a[i];
		}
		
		if (sum > maxVal)
		{
			maxVal = sum;
		}
	}

	return maxVal;
}

int maxSumDP(int arr[], int length)
{
	int sum = 0;
	int maxVal = 0;

	//sum[i]��ʾ����i������i��β��������еĳ���
	//��sum[i+1] = max(sum[i]+a[i+1], a[i+1]);	�����maxΪ����ôȡֵ���Բο���һ�ֽⷨ
	//maxVal = max(maxVal, sum[i+1]);
	for (int i = 0; i < length; i++)
	{
		sum = max(sum+arr[i],arr[i]);
		//maxVal = max(sum,maxVal);
		maxVal = sum > maxVal ? sum : maxVal;
	}

	return maxVal;
}

int main()
{
	int a[5] = {2,-1,3,2,-1};
	int length = 5;

	cout<<maxSum(a,length)<<endl;
	cout<<maxSumDP(a,length)<<endl;

	getchar();
	return 0;
}