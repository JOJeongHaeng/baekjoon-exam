#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cost[1001];
int dp[1001];
int indegree[1001];

vector<vector<int>> vec;

int main()
{
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		int N, K;
		cin >> N >> K;

		vec = vector<vector<int>>(1001, vector<int>());

		for (int j = 1; j <= N; j++)
		{
			cin >> cost[j];
			dp[j] = cost[j];
		}
		for (int j = 1; j <= K; j++)
		{
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			indegree[b]++;
		}
		int cnt;
		cin >> cnt;

		queue<int> q;
		for (int j = 1; j <= N; j++)
		{
			if (indegree[j] == 0)
			{
				q.push(j);
			}
		}
		while (!q.empty())
		{
			int current = q.front();
			q.pop();

			for (int j = 0; j < vec[current].size(); j++)
			{
				int next = vec[current][j];
				dp[next] = max(dp[next], dp[current] + cost[next]);
				if (--indegree[next] == 0) q.push(next);
			}
		}
		cout << dp[cnt] << endl;
	}

	return 0;
}