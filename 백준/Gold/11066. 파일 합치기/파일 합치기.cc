#include <iostream>
#include <memory.h>
#include <limits.h>

using namespace std;

int T, N;
long long dp[501][501];
int files[501];
long long sum[501];

int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		memset(dp, 0, sizeof(dp));
		memset(files, 0, sizeof(files));
		memset(sum, 0, sizeof(sum));

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> files[i];
			sum[i] = sum[i - 1] + files[i];
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j + i <= N; j++)
			{
				dp[j][i + j] = INT_MAX;
				for (int k = j; k <= i + j; k++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][N] << '\n';
	}

	return 0;
}