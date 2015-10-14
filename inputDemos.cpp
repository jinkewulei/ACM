#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int numTestCases;
	cin>>numTestCases;

	while (numTestCases--)
	{
		//处理每个case
		int N;
		cin>>N;

		vector <vector<int> > imageA(N), imageB(N);
		for(int i = 0;i < N;i++)
		{
			imageA[i].resize(N);
			imageB[i].resize(N);
		}

		//输入图像A
		for (int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cin>>imageA[i][j];
			}
		}
		//输入图像B
		for (int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cin>>imageB[i][j];
			}
		}
		
		//测试输入
		cout<<endl<<"output:"<<endl;
		for (int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cout<<imageA[i][j]<<" ";
			}
			cout<<endl;
		}
		for (int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cout<<imageB[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	getchar();getchar();
	return 0;
}
