#include <iostream>

using namespace std;

int n;

void f(int num)
{
	if (num == 0) return;
	f(num - 1);
	cout << num << '\n';
	f(num - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cout << (1 << n) - 1 << '\n';

	f(n);
	cout << n;

	return 0;
}