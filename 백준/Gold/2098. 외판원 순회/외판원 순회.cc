#include <iostream>
#include <memory.h>

#define INF 987654321

using namespace std;

int N, answer_bit;
int map[16][16];
int dp[16][1 << 16];

int dfs(int cur, int cur_bit)
{
	if (cur_bit == answer_bit)
	{
		if (map[cur][0] == 0) return INF;
		else return map[cur][0];
	}

	if (dp[cur][cur_bit] != -1) return dp[cur][cur_bit];
	dp[cur][cur_bit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (map[cur][i] == 0) continue;
		if ((cur_bit & (1 << i)) == (1 << i)) continue;

		dp[cur][cur_bit] = min(dp[cur][cur_bit], map[cur][i] + dfs(i, cur_bit | 1 << i));
	}
	return dp[cur][cur_bit];
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	answer_bit = (1 << N) - 1;
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);

	return 0;
}