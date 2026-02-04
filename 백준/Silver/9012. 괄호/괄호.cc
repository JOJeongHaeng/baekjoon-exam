#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		queue<char> q;
		for (char c : str)
		{
			q.push(c);
		}
		int cnt = 0;
		while (!q.empty())
		{
			if (q.front() == '(') cnt++;
			else cnt--;
			if (cnt < 0) break;
			q.pop();
		}
		cout << (cnt == 0 ? "YES" : "NO") << endl;
	}

	return 0;
}