#include <iostream>
#include <limits.h>

using namespace std;

int arr[101];
int dp[10001];

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= K; i++)
	{
		dp[i] = INT_MAX - 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = arr[i]; j <= K; j++)
		{	
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[K] == INT_MAX - 1) cout << -1 << endl;
	else cout << dp[K] << endl;

	return 0;
}