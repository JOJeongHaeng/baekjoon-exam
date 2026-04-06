#include <iostream>
#define MAX 9

using namespace std;

int N, l;
int arr[MAX];

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
	for (int i = idx; i <= n; i++)
	{
		arr[cnt] = i;
		f(i, n, cnt + 1);
	}
}

int main()
{	
	cin >> N >> l;
	f(1, N, 0);

	return 0;
}