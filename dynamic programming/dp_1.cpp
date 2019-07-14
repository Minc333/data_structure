/*有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法？
  采用递归和非递归方式
*/

#include<iostream>
using namespace std;
#define N 20

int recDp[N];
int dp[N];
int rec_dp(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	else
	{
		recDp[n - 1] = rec_dp(n - 1);
		recDp[n - 2] = rec_dp(n - 2);
		recDp[n] = recDp[n - 1] + recDp[n - 2];
		return recDp[n];
	}
}

void dp_opt(int n)
{
	dp[1] = 1;
	dp[2] = 2;
	if (n == 1 || n == 2)
		return;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main()
{
	rec_dp(N);
	dp_opt(N);
	cout << dp[1] << endl;
	cout << dp[2] << endl;
	cout << dp[3] << endl;
	cout << dp[4] << endl;
	cout << dp[5] << endl;
	cout << dp[6] << endl;
	cout << dp[7] << endl;
	cout << dp[8] << endl;
	cout << dp[9] << endl;
	cout << dp[10] << endl;
	cout << dp[11] << endl;
	cout << dp[12] << endl;
	cout << dp[13] << endl;
	cout << dp[14] << endl;
	cout << dp[15] << endl;
	cout << dp[16] << endl;
	cout << dp[17] << endl;
	cout << dp[18] << endl;
	cout << dp[19] << endl;
	cout << dp[20] << endl;

	cout << recDp[1] << endl;
	cout << recDp[2] << endl;
	cout << recDp[3] << endl;
	cout << recDp[4] << endl;
	cout << recDp[5] << endl;
	cout << recDp[6] << endl;
	cout << recDp[7] << endl;
	cout << recDp[8] << endl;
	cout << recDp[9] << endl;
	cout << recDp[10] << endl;
	cout << recDp[11] << endl;
	cout << recDp[12] << endl;
	cout << recDp[13] << endl;
	cout << recDp[14] << endl;
	cout << recDp[15] << endl;
	cout << recDp[16] << endl;
	cout << recDp[17] << endl;
	cout << recDp[18] << endl;
	cout << recDp[19] << endl;
	cout << recDp[20] << endl;
	getchar();
	return 0;
}