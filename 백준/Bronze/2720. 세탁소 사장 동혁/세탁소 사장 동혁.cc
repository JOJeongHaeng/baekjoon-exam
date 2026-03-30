#include <iostream>

using namespace std;

int T, N;
int money[4] = { 25, 10, 5, 1 };

int main()
{	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int answer[4] = { 0, 0, 0, 0 };
		cin >> N;
		for (int i = 0; i < 4; i++)
		{
			while (N >= money[i])
			{
				answer[i] = N / money[i];
				N %= money[i];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}