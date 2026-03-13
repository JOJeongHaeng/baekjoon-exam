#include <iostream>

#define MAX_N 1500002
int n, answer;
int arr[MAX_N][2];
int dp[MAX_N];

using namespace std;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
}

void Solutuin()
{
	answer = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		answer = max(answer, dp[i]);
	
		if (i + arr[i][0] > n + 1) continue;
		dp[i + arr[i][0]] = max(dp[i + arr[i][0]], answer + arr[i][1]);
	}
}

void Solve()
{
	Input();
	Solutuin();
	cout << answer << endl;
}

int main()
{
	Solve();
	return 0;
}