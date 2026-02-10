#include <iostream>

using namespace std;

int dp[41];
int code1 = 0;
int code2 = 0;

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		code1++;
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int N;
	cin >> N;

	fib(N);

	dp[1] = dp[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
		code2++;
	}

	cout << code1 << " " << code2;
	return 0;
}