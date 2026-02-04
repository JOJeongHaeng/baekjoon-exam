#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& Vec, vector<bool>& visit , int now, vector<int>& answer)
{
	visit[now] = true;
	answer.push_back(now);
	for (int i = 0; i < Vec[now].size(); i++)
	{
		if (!visit[Vec[now][i]]) dfs(Vec, visit, Vec[now][i], answer);
	}
}

void bfs(const vector<vector<int>>& Vec, vector<bool>& visit, queue<pair<int, int>>& q, vector<int>& answer)
{
	while (!q.empty())
	{
		auto p = q.front();
		if (!visit[p.second])
		{
			visit[p.second] = true;
			answer.push_back(p.second);
		}
		q.pop();
		for (int i = 0; i < Vec[p.second].size(); i++)
		{
			if (!visit[Vec[p.second][i]])
			{
				q.push({ p.second, Vec[p.second][i] });
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> Vec(N + 1, vector<int>());
	vector<bool> visit(N + 1, false);
	vector<int> DFSAnser; 
	vector<int> BFSAnser;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Vec[a].push_back(b);
		Vec[b].push_back(a);
	}

	for (int i = 0; i < Vec.size(); i++)
	{
		sort(Vec[i].begin(), Vec[i].end());
	}

	//dfs
	dfs(Vec, visit, V, DFSAnser);

	//bfs
	visit = vector<bool>(N + 1, false);
	
	queue<pair<int, int>> q;

	for (int i = 0; i<Vec[V].size(); i++)
	{
		q.push({ V, Vec[V][i] });
	}
	visit[V] = true;
	BFSAnser.push_back(V);

	bfs(Vec, visit, q, BFSAnser);

	// 출력
	for (int i = 0; i < DFSAnser.size(); i++) cout << DFSAnser[i] << " ";
	cout << '\n';
	for (int i = 0; i < BFSAnser.size(); i++) cout << BFSAnser[i] << " ";
	return 0;
}