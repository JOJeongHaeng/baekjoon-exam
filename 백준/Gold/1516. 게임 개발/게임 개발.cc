#include <iostream>
#include <vector>
#include <queue>

#define MAX 501

using namespace std;

int n, tmp;
int dp[MAX];
int build_time[MAX], entry[MAX];
vector<int> preceding[MAX];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> build_time[i];
		cin >> tmp;
		while (tmp != -1)
		{
			preceding[tmp].push_back(i);
			entry[i]++;
			cin >> tmp;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (entry[i] == 0)
		{
			dp[i] = build_time[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < preceding[cur].size(); i++)
		{
			int next = preceding[cur][i];
			entry[next]--;
			dp[next] = max(dp[next], dp[cur] + build_time[next]);
			if (entry[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << '\n';
	}

	return 0;
}