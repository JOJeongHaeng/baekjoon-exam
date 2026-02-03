#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int N;
	cin >> N;

	int ln = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] < arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
			ln = ln > dp[i] ? ln : dp[i];
		}
	}
	cout << ln << '\n';
	return 0;
}