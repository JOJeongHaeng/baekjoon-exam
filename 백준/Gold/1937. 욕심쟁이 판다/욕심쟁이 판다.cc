#include <iostream>

using namespace std;

int n;
int dp[501][501];
int map[501][501];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int dfs(int y, int x)
{
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY > 0 && nextX > 0 && nextY <= n && nextX <= n)
		{
			if (map[y][x] < map[nextY][nextX])
			{
				dp[y][x] = max(dp[y][x], dfs(nextY, nextX) + 1);
			}
		}
	}
	return dp[y][x];
}

int main()
{
	cin >> n;
	
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			answer = max(answer, dfs(i, j));
		}
	}

	cout << answer;
	return 0;
}