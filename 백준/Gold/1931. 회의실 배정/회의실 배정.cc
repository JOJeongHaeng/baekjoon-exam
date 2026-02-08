#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	
	sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
		{
			if (p1.second == p2.second) return p1.first < p2.first;
			return p1.second < p2.second;
		});

	int time = v[0].second;
	int answer = 1;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first >= time)
		{
			answer++;
			time = v[i].second;
		}
	}
	cout << answer << '\n';
	return 0;
}