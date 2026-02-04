#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	map<string, bool> m;
	set<string> s;

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		m[str] = 1;
	}
	for (int i = 1; i <= M; i++)
	{
		string str;
		cin >> str;
		if (m[str])
		{
			cnt++;
			s.insert(str);
		}
	}

	cout << cnt << '\n';
	for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << '\n';
	}

	return 0;
}