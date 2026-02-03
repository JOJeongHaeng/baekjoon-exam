#include <iostream>

using namespace std;

long long arr[2][100002];
long long dp[2][100002];

int main()
{
	int T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				cin >> arr[j][k];
			}
		}
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int k = 2; k <= N; k++)
		{
			dp[0][k] = max(dp[1][k - 1] + arr[0][k], dp[1][k - 2] + arr[0][k]);
			dp[1][k] = max(dp[0][k - 1] + arr[1][k], dp[0][k - 2] + arr[1][k]);
		}
		cout << max(dp[0][N], dp[1][N]) << endl;
	}
	return 0;
}