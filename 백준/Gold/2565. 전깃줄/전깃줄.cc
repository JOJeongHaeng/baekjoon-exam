#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	
	sort(v.begin(), v.end());

	int answer = 0;
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > answer) answer = dp[i];
			}
		}
	}
	cout << N - answer;
	return 0;
}