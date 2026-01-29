#include <iostream>

using namespace std;

long long arr[91];

int main()
{
	int N;
	cin >> N;
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cout << arr[N];
	return 0;
}