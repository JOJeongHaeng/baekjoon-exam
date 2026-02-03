#include <iostream>

using namespace std;

int arr[1001];
int dpL[1001];
int dpR[1001];

int main()
{
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		dpL[i] = 1;
		dpR[N - i + 1] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dpL[i] < dpL[j] + 1)
			{
				dpL[i] = dpL[j] + 1;
			}
		}
	}
	for (int i = N; i >= 1; i--)
	{
		dpR[i] = 1;
		for (int j = N; j >= i; j--)
		{
			if (arr[j] < arr[i] && dpR[i] < dpR[j] + 1)
			{
				dpR[i] = dpR[j] + 1;
			}
		}
	}

	int mx = 0;
	for (int i = 1; i <= N; i++)
	{
		if (mx < dpR[i] + dpL[i] - 1) mx = dpR[i] + dpL[i] - 1;
	}

	cout << mx << '\n';
	return 0;
}