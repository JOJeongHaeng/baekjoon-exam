#include <iostream>
#define MAX 9

using namespace std;

int N, l;
int arr[MAX];
bool vis[MAX];

void f(int n, int cnt)
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
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			arr[cnt] = i;
			vis[i] = true;
			f(n, cnt + 1);
			vis[i] = false;
		}
	}
}

int main()
{	
	cin >> N >> l;
	f(N, 0);

	return 0;
}