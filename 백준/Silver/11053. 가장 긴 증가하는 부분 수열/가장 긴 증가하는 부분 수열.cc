#include <iostream>

using namespace std;

int main()
{
	int N, answer = 1;
	cin >> N;
	int arr[1001];
	int dp[1001];
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
		dp[i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	for (int i = 1; i <= N; i++) answer = max(answer, dp[i]);
	cout << answer;
	return 0;
}