#include <iostream>
#include <queue>

using namespace std;

bool arr[10001];

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
	for (int i = 1; i <= 10000; i++)
	{
		int tmp = f(i);
		if (tmp < 10001) arr[tmp] = true;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!arr[i]) cout << i << '\n';
	}

	return 0;
}