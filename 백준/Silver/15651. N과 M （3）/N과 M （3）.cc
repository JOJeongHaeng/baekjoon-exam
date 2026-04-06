#include <iostream>

#define MAX 7

using namespace std;

int n, m;
int arr[MAX];

void f(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[cnt] = i;
		f(cnt + 1);
	}
}

int main()
{
	cin >> n >> m;
	f(0);
	return 0;
}