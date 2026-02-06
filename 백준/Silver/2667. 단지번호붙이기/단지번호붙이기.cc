#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
bool visit[26][26];

vector<pair<int, int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int dfs(int y, int x, int house)
{
	visit[y][x] = true;
	house++;
	for (int i = 0; i < 4; i++)
	{
		if (arr[y + dir[i].first][x + dir[i].second] == 1 && !visit[y + dir[i].first][x + dir[i].second])
		{
			house = dfs(y + dir[i].first, x + dir[i].second, house);
		}
	}
	return house;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		visit[0][i] = true;
		visit[i][0] = true;
	}

	vector<int> answer;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visit[i][j] && arr[i][j] == 1)
			{
				cnt++;
				answer.push_back(dfs(i, j, 0));
			}
		}
	}

	sort(answer.begin(), answer.end(), less<int>());

	cout << cnt << '\n';
	for (int i : answer)
	{
		cout << i << '\n';
	}
	return 0;
}