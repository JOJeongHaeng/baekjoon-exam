#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int N;
	int mx = 0;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i])
			{
				dp[i] = dp[j] + arr[i];
			}
		}
		mx = mx > dp[i] ? mx : dp[i];
	}
	
	cout << mx << '\n';
	return 0;
}