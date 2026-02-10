#include <iostream>

using namespace std;

int arr[2001];
bool dp[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) dp[i][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == arr[i - 1]) dp[i - 1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j + i <= N; j++)
		{
			if (arr[j] == arr[j + i] && dp[j + 1][i + j - 1] == 1) dp[j][i + j] = 1;
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int left, right;
		cin >> left >> right;
		cout << dp[left][right] << "\n";
	}

	return 0;
}