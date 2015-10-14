#include <iostream>
using namespace std;

//算法复杂度O(n)
//思想：从头扫描此数组，只要第m-n项的加权大于0
//那么这第m-n项对第n+1项就是有正增益的，继续相加下一项
//如果第m-n项小于0了，那么把他们相加下去肯定对后续有衰减，故重新置m
//每一次相加的结果都会和maxVal比较，所以maxVal总能存储最大值
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