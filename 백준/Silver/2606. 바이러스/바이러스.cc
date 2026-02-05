#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec(101, vector<int>());
bool visit[101];
int answer = -1;

void dfs(int num)
{
	visit[num] = true;
	answer++;
	for (int i = 0; i < vec[num].size(); i++)
	{
		if (!visit[vec[num][i]])
		{
			dfs(vec[num][i]);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	dfs(1);
	cout << answer;

	return 0;
}