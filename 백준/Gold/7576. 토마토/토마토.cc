#include <iostream>
#include <queue>

int m, n;
int map[1001][1001];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

using namespace std;

int main()
{
	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}
	int cnt = q.size();
	int tmp = 0, answer = -1;

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		tmp++;

		for (int i = 0; i < 4; i++)
		{
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if (nx > 0 && ny > 0 && nx <= m && ny <= n && map[ny][nx] == 0)
			{
				map[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		
		if (cnt == tmp)
		{
			answer++;
			cnt = q.size();
			tmp = 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer;
	return 0;
}