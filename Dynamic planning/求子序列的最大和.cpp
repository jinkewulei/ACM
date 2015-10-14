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

int maxSumDP(int arr[], int length)
{
	int sum = 0;
	int maxVal = 0;

	//sum[i]表示放入i并且以i结尾的最长子序列的长度
	//则sum[i+1] = max(sum[i]+a[i+1], a[i+1]);	不理解max为何这么取值可以参考第一种解法
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