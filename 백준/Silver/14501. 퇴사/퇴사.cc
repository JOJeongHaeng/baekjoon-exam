#include <iostream>

using namespace std;

int arr[2][16];
int dp[16] = { 0, };
int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int T, P;
		cin >> T >> P;
		arr[0][i] = T;
		arr[1][i] = P;
	}

	for (int i = N; i >= 1; i--)
	{
		int deadline = i + arr[0][i];
		if ( deadline > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[deadline] + arr[1][i]);
		}
	}
	
	cout << dp[1];
	return 0;
}