#include <iostream>
#define MAX 15

using namespace std;

int N, total = 0;
int col[MAX];

bool check(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (col[i] == col[num] || abs(col[i] - col[num]) == num - i)
		{
			return false;
		}
	}
	return true;
}
void f(int x)
{
	if (x == N)
	{
		total++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		col[x] = i;
		if (check(x))
		{
			f(x + 1);
		}
	}
	
}

int main()
{	
	cin >> N;
	f(0);
	cout << total;
	return 0;
}