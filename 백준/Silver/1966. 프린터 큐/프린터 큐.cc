#include <iostream>
#include <queue>

#define MAX 10001

using namespace std;

int T, N, idx, tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		int cnt = 0;
		cin >> N >> idx;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			q.push({ i, tmp });
			pq.push(tmp);
		}
		while (!q.empty())
		{
			int index = q.front().first;
			int val = q.front().second;
			q.pop();
			if (val == pq.top())
			{
				pq.pop();
				cnt++;
				if (idx == index)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
			{
				q.push({ index, val });
			}
		}
	}

	return 0;
}