#include <iostream>

using namespace std;

int arr[5001];

int main()
{
	int N;
	cin >> N;
	
	arr[3] = arr[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		if (arr[i - 3]) arr[i] = arr[i - 3] + 1;
		if (arr[i - 5]) arr[i] = arr[i - 5] + 1;
	}
	if (arr[N] == 0) cout << -1;
	else cout << arr[N];
	return 0;
}