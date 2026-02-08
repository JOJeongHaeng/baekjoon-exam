#include <iostream>
#include <queue>

using namespace std;

int f(int num)
{
	int tmp = num;
	while (num / 10)
	{
		tmp += num % 10;
		num /= 10;
	}
	tmp += num;
	return tmp;
}

int main()
{
	int N;
	cin >> N;
	bool check = true;

	for (int i = N / 2; i <= N; i++)
	{
		int tmp = f(i);
		if (tmp == N)
		{
			check = false;
			cout << i << endl;
			break;
		}
	}
	if (check) cout << 0 << endl;
	return 0;
}