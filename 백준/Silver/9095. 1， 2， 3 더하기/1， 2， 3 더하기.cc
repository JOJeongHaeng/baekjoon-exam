#include <iostream>

using namespace std;

void dfs(int now, const int n, int& cnt)
{
	if (now == n)
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		if (now + i <= n)
		{
			dfs(now + i, n, cnt);
		}
	}
}

int main()
{
	int T, n, cnt = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 1; j <= 3; j++)
		{
			dfs(j, n, cnt);
		}
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}