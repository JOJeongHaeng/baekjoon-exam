#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int cnt = 1, score = 0;
		for (char c : str)
		{
			if (c == 'O')
			{
				score += cnt;
				cnt++;
			}
			else
			{
				cnt = 1;
			}
		}
		cout << score << '\n';
	}

	return 0;
}