#include <iostream>

using namespace std;

int n, m, mn;
int map[1001][1001];

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0) continue;
			map[i][j] = min(min(map[i - 1][j - 1], map[i - 1][j]), map[i][j - 1]) + 1;
			if (map[i][j] > answer) answer = map[i][j];
		}
	}
	cout << answer * answer;
	return 0;
}