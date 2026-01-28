#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int answer = 1;
		int r, n;
		cin >> r >> n;
		int k = 1;
		for (int j = n; j > n - r; j--)
		{
			answer *= j;
			answer /= k;
			k++;
		}

		cout << answer << endl;
	}
	
	return 0;
}