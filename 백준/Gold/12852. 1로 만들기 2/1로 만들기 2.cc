#include <iostream>

using namespace std;

int dp[1000001];
int arr[1000001];

int main()
{
	int N;
	cin >> N;
	
	dp[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}

	cout << dp[N] << "\n";

	while (!(N == 1))
	{
		cout << N << " ";
		int tmp = N - 1;
		if (N % 3 == 0) tmp = dp[N - 1] < dp[N / 3] ? N - 1 : N / 3;
		if (N % 2 == 0) tmp = dp[tmp] < dp[N / 2] ? tmp : N / 2;
		N = tmp;
	}
	cout << 1;
	return 0;
}