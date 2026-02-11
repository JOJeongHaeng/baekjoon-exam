#include <iostream>

#define div 1000000009

using namespace std;

int N;
long long dp[1000001];

void fill_dp()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % div;
	}
}

int main()
{
	int T;
	cin >> T;
	fill_dp();

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}