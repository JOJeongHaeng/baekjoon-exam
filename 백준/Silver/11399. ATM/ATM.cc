#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int answer = 0;
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		answer += total + arr[i];
		total += arr[i];
	}

	cout << answer << '\n';
	return 0;
}