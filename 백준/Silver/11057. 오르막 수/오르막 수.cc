#include <iostream>

using namespace std;

int dp[1001][10];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] % 10007;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum += dp[N][i];
	}
	cout << sum % 10007 << "\n";
	return 0;
}