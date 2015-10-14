#include <iostream>
using namespace std;

int package(int value[], int weight[], int capacity, int length, int m[][11])
{
	//从下向上生成表格
	for (int i = 0; i < capacity+1; i++)
	{
		if (weight[length-1]>i)
		{
			m[length-1][i] = 0;
		}
		else
		{
			m[length-1][i] = value[length-1];
		}
	}

	for (int i = length-2; i >= 0; i--)
	{
		for (int j = 1; j <= capacity; j++)
		{
			if (weight[i] > j)
			{
				m[i][j] = m[i+1][j];
			}
			else
			{
				m[i][j] = max(m[i+1][j],m[i+1][j-weight[i]]+value[i]);
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}

	return 0;
}

int inPnapsack(int length, int capacity, int m[][11], int result[], int weight[])
{
	for (int i = 0; i < length-1; i++)
	{
		if (m[i][capacity] == m[i+1][capacity])
		{
			result[i] = 0;
		}
		else
		{
			result[i] = 1;
			capacity = capacity - weight[i];
		}
	}
	//result[length-1] = capacity < weight[length-1] ? 0 : 1;
	//OR
	result[length-1] = m[length-1][capacity] == 0 ? 0 : 1;

	return 0;
}

int main()
{
	int value[5] = {6,3,5,4,6};
	int weight[5] = {2,2,6,5,4};
	int result[5] = {0};
	int length = 5;
	int capacity = 10;
	int m[5][11] = {0};

	package(value, weight, capacity, length, m);
	cout<<endl<<m[0][10]<<endl;

	inPnapsack(length, capacity, m, result, weight);
	for (int i = 0; i < length; i++)
	{
		cout<<result[i]<<"  ";
	}
	getchar();
	return 0;
}