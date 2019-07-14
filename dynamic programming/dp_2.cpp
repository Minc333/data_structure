/*
����һ������m�������Ͻǿ�ʼÿ��ֻ�������߻��������ߣ����ﵽ���½ǵ�λ�ã�·�������������ۼ���������·���ͣ���������·������С·���ͣ����������m���£���ô·��1,3,1,0,6,1,0������С·���ͣ�����12.
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