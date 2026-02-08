#include <iostream>

using namespace std;

int arr[11];

int main()
{
	int N, K;
	cin >> N >> K;
	int answer = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	for (int i = N - 1; i >= 0; i--)
	{
		if (K == 0) break;
		if (K / arr[i] == 0) continue;
		answer += K / arr[i];
		K %= arr[i];
	}

	cout << answer << '\n';
	return 0;
}