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

int main()
{
	int a[5] = {2,3,-3,1,1};
	int length = 5;

	cout<<maxSum(a,length);

	getchar();
	return 0;
}