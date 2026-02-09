#include <iostream>

using namespace std;

int arr[502][502];
int dp[502][502];
int M, N;

pair<int, int> test[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int dfs(int y, int x)
{
	if (y == M && x == N) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (auto p : test)
	{
		if (arr[y + p.first][x + p.second] != 0 && arr[y][x] > arr[y + p.first][x + p.second])
		{
			dp[y][x] = dp[y][x] + dfs(y + p.first, x + p.second);
		}
	}
	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	int answer = dfs(1, 1);

	cout << answer;
	return 0;
}