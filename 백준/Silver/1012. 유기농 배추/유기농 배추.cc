#include <iostream>
#include <memory.h>

using namespace std;

bool map[51][51];
bool visit[51][51];
int answer = 0;
pair<int, int> test[4] = { {1,0}, {0,1}, {0, -1}, {-1, 0} };

void dfs(int y, int x)
{
	visit[y][x] = true;
	for (pair<int, int> p : test)
	{
		if (map[y + p.first][x + p.second] && !visit[y + p.first][x + p.second])
		{
			dfs(y + p.first, x + p.second);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, K;
		cin >> M >> N >> K;
		int answer = 0;

		for (int j = 0; j < 51; j++)
		{
			memset(visit[j], false, sizeof(visit[j]));
			memset(map[j], false, sizeof(map[j]));
		}

		for (int j = 0; j < K; j++)
		{
			int y, x;
			cin >> y >> x;
			map[y][x] = true;
		}

		for (int y = 0; y < M; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (map[y][x] && !visit[y][x])
				{
					dfs(y, x);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}