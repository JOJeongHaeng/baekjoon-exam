#include <iostream>
#include <queue>

using namespace std;

int arr[101];
bool visit[101];
int answer = 0;
int N, M;

void dfs(int idx, int num, int cnt)
{
	if (cnt == 3)
	{
		if (num <= M && answer < num) answer = num;
		return;
	}
	for (int i = idx + 1; i < N; i++)
	{
		if (!visit[i]) dfs(i, num + arr[i], cnt + 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		visit[i] = true;
		dfs(i, arr[i], 1);
		visit[i] = false;
	}

	cout << answer;
	return 0;
}