/*
给定一个矩阵m，从左上角开始每次只能向右走或者向下走，最后达到右下角的位置，路径中所有数字累加起来就是路径和，返回所有路径的最小路径和，如果给定的m如下，那么路径1,3,1,0,6,1,0就是最小路径和，返回12.
*/
#include<iostream>
using namespace std;

int dp[4][4] = {};

void dp_fun(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
			{
				dp[i][j] = a[0][0];
			}
			else if (i == 0 && j != 0)
			{
				dp[i][j] = a[i][j] + dp[i][j - 1];
			}
			else if (i != 0 && j == 0)
			{
				dp[i][j] = a[i][j] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? a[i][j] + dp[i][j - 1] : a[i][j] + dp[i - 1][j];
			}

		}
	}
}

int main()
{
	int a[4][4] = { 2,5,1,8,7,3,6,9,3,2,1,4,2,6,5,1 };
	dp_fun(a);
	cout << dp[3][3] << endl;
	getchar();
	return 0;
}