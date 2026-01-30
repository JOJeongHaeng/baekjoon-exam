#include <iostream>

using namespace std;

int arr[101][10];

int main()
{
	int N;
	cin >> N;
	
	for (int i = 1; i <= 9; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) arr[i][j] = arr[i - 1][j + 1];
			else if (j == 9) arr[i][j] = arr[i - 1][j - 1];
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			}
			arr[i][j] %= 1000000000;
		}
	}
	int answer = 0;
	for (int i = 0; i <= 9; i++)
	{
		answer = (answer + arr[N][i]) % 1000000000;
	}
	cout << answer;
	return 0;
}