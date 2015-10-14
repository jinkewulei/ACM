#include <iostream>
#include <string>
using namespace std;

//输入一个数字字符串，转换为货币格式，即每三位加一个逗号隔开
int main()
{
	string str;
	cin>>str;

	int length = str.length();
	int mod = length%3;
	if (length<=3)
	{
		cout<<str;
	}
	else if(mod<3 && mod >0)
	{
		int i = 0;
		for (i = 0;i < mod;i++)
		{
			cout<<str[i];
		}
		cout<<",";
		for (; i < length-3; i+=3)
		{
			cout<<str[i]<<str[i+1]<<str[i+2];
			cout<<",";
		}
		cout<<str[i]<<str[i+1]<<str[i+2];
	}
	else
	{
		int i = 0;
		for (i = 0; i < length-3; i+=3)
		{
			cout<<str[i]<<str[i+1]<<str[i+2];
			cout<<",";
		}
		cout<<str[i]<<str[i+1]<<str[i+2];
	}

	getchar();getchar();
	return 0;
}