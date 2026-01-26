#include <iostream>

using namespace std;

int arr[301];
int visit[301];

int f(int n)
{
	if (n <= 0) return 0;
	if (visit[n]) return visit[n];
	int a = arr[n] + f(n - 2);
	int b = arr[n] + arr[n - 1] + f(n - 3);
	int save = a > b ? a : b;

	return visit[n] = save;
}

int main()
{
	int n, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
	}
	visit[1] = arr[1];
	visit[2] = arr[1] + arr[2];

	f(n);

	cout << visit[n];
	return 0;
}