#include <iostream>
#include <queue>

using namespace std;

bool arr[10000001];

int main()
{
	int X;
	cin >> X;

	queue<pair<int, int>> q;
	q.push({ X, 0 });
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		int idx = p.first;
		int cnt = p.second;

		if (idx == 1)
		{
			cout << cnt;
			break;
		}
		if (idx % 3 == 0 && !arr[idx/3])
		{
			q.push({ idx / 3, cnt + 1 });
		}
		if (idx % 2 == 0 && !arr[idx / 2])
		{
			q.push({ idx / 2, cnt + 1 });
		}
		if (!arr[idx - 1])
		{
			q.push({ idx - 1, cnt + 1 });
		}
	}

	return 0;
}