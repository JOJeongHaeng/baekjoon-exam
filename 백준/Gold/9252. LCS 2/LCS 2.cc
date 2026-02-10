#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int first = str1.size();
	int second = str2.size();

	for (int i = 0; i <= first; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j <= second; j++)
	{
		dp[0][j] = 0;
	}

	for (int i = 1; i <= first; i++)
	{
		for (int j = 1; j <= second; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	string answer = "";
	for (int i = first; i >= 1; i--)
	{
		for (int j = second; j >= 1; j--)
		{
			if (dp[i][j] == dp[i - 1][j])
			{
				second = j;
				break;
			}
			else if (dp[i][j] == dp[i][j - 1])
			{
				continue;
			}
			else answer = str1[i - 1] + answer;
		}
	}

	cout << dp[str1.size()][str2.size()] << '\n' << answer;
	return 0;
}