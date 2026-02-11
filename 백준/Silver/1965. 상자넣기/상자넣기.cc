#include <iostream>

using namespace std;

int n;
int boxes[1001];
int dp[1001];

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> boxes[i];
	}

	dp[1] = 1;
	
	int answer = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (boxes[j] < boxes[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				if (answer < dp[i]) answer = dp[i];
			}
		}
	}

	cout << answer;
	return 0;
}