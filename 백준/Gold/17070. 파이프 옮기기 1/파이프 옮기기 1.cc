#include <iostream>
#include <queue>

using namespace std;

int map[17][17];
int dp[17][17];
int N;

void dfs(char dir, int y, int x)
{
	switch (dir)
	{
	case 'X':
		if (y + 1 <= N && x + 1 <= N)
		{
			if (map[y + 1][x + 1] == 0 && map[y + 1][x] == 0 && map[y][x + 1] == 0)
			{
				dp[y + 1][x + 1]++;
				dfs('X', y + 1, x + 1);
			}
		}
		
		if (x + 1 <= N)
		{
			if (map[y][x + 1] == 0)
			{
				dp[y][x + 1]++;
				dfs('R', y, x + 1);
			}
		}
		
		if (y + 1 <= N)
		{
			if (map[y + 1][x] == 0)
			{
				dp[y + 1][x]++;
				dfs('D', y + 1, x);
			}
		}
		break;

	case 'R' :
		if (y + 1 <= N && x + 1 <= N)
		{
			if (map[y + 1][x + 1] == 0 && map[y + 1][x] == 0 && map[y][x + 1] == 0)
			{
				dp[y + 1][x + 1]++;
				dfs('X', y + 1, x + 1);
			}
		}

		if (x + 1 <= N)
		{
			if (map[y][x + 1] == 0)
			{
				dp[y][x + 1]++;
				dfs('R', y, x + 1);
			}
		}
		break;

	case 'D':
		if (y + 1 <= N && x + 1 <= N)
		{
			if (map[y + 1][x + 1] == 0 && map[y + 1][x] == 0 && map[y][x + 1] == 0)
			{
				dp[y + 1][x + 1]++;
				dfs('X', y + 1, x + 1);
			}
		}

		if (y + 1 <= N)
		{
			if (map[y + 1][x] == 0)
			{
				dp[y + 1][x]++;
				dfs('D', y + 1, x);
			}
		}
		break;
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[1][2] = 1;
	dfs('R', 1, 2);

	cout << dp[N][N];
	return 0;
}