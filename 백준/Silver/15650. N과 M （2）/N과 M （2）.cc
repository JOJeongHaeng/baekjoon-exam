#include <iostream>
#define MAX 9

using namespace std;

int N, l;
int arr[MAX];
bool vis[MAX];

void f(int idx, int n, int cnt)
{
	if (cnt == l)
	{
		for (int i = 0; i < l; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx + 1; i <= n; i++)
	{
		if (!vis[i])
		{
			arr[cnt] = i;
			vis[i] = true;
			f(i, n, cnt + 1);
			vis[i] = false;
		}
	}
}

int main()
{	
	cin >> N >> l;
	f(0, N, 0);

	return 0;
}