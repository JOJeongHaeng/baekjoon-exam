#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int visit[101][101];

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	pair<int, int> test[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 1 }, 1 });
	while (!q.empty())
	{
		auto p = q.front();
		int y = p.first.first;
		int x = p.first.second;
		int cnt = p.second;
		q.pop();

		if (p.first == make_pair(N, M))
		{
			cout << cnt << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			if (arr[y + test[i].first][x + test[i].second] == 1 && !visit[y + test[i].first][x + test[i].second])
			{
				visit[y + test[i].first][x + test[i].second] = true;
				q.push({ {y + test[i].first, x + test[i].second}, cnt + 1 });
			}
		}
	}

	return 0;
}