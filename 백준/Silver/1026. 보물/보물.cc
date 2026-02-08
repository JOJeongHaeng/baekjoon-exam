#include <iostream>
#include <algorithm>

using namespace std;

int A[51];
int B[51];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += A[i] * B[i];
	}
	cout << answer;
	return 0;
}