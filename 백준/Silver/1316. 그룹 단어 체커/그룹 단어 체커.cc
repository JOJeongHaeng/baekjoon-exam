#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		set<char> s;
		char last = str[0];
		s.insert(str[0]);
		bool check = false;

		for (char c : str)
		{
			if (last == c) continue;
			if (s.find(c) != s.end())
			{
				check = true;
				break;
			}
			else
			{
				s.insert(c);
			}
			last = c;
		}
		if (!check) answer++;
	}

	cout << answer;

	return 0;
}