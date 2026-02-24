#include <iostream>

#define MAX_N 1000001
int n;
int cost[1001][3];
int dp[1001][3];

using namespace std;

int main()
{
	int answer = MAX_N;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
		}
	}

	for (int RGB = 0; RGB < 3; RGB++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (RGB == i) dp[1][i] = cost[1][i];
			else dp[1][i] = MAX_N;
		}

		for (int i = 2; i <= n; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == RGB) continue;
			else
			{
				answer = min(answer, dp[n][i]);
			}
		}
	}

	cout << answer;
	return 0;
}