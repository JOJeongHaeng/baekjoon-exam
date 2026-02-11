#include <iostream>

using namespace std;

long long dp[101][101];
int dy[] = { 0, 1 };
int dx[] = { 1, 0 };
int N;


int main()
{
	cin >> N;
	
	dp[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			if (!num) continue;
			for (int k = 0; k < 2; k++)
			{
				int nextY = i + dy[k] * num;
				int nextX = j + dx[k] * num;
				if (nextY > N || nextX > N) continue;
				dp[nextY][nextX] += dp[i][j];
			}
		}
	}

	cout << dp[N][N];
	return 0;
}