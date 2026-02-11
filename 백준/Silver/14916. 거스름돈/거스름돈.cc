#include <iostream>

using namespace std;

int dp[100001];
int N;


int main()
{
	cin >> N;
	dp[0] = 0;
	dp[1] = 50001;
	for (int i = 2; i < 5; i++)
	{
		dp[i] = 50001;
		dp[i] = min(dp[i - 2] + 1, dp[i]);
	}
	for (int i = 5; i <= N; i++)
	{
		dp[i] = 50001;
		dp[i] = min(dp[i - 2] + 1, dp[i]);
		dp[i] = min(dp[i - 5] + 1, dp[i]);
	}
	cout << (dp[N] == 50001 ? -1 : dp[N]);

	return 0;
}