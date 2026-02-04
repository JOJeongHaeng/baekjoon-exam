#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

void f(string str, stack<int>& st)
{
	stringstream ss(str);
	string tmp;
	while (getline(ss, tmp, ' '))
	{
		if (tmp == "push") continue;
		else if (tmp == "pop")
		{
			if (st.empty()) cout << -1 << endl;
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (tmp == "size") cout << st.size() << endl;
		else if (tmp == "empty") cout << st.empty() << endl;
		else if (tmp == "top")
		{
			if (st.empty()) cout << -1 << endl;
			else cout << st.top() << endl;
		}
		else st.push(stoi(tmp));
	}
}

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	stack<int> st;

	for (int i = 1; i <= N; i++)
	{
		string str;
		getline(cin, str);
		f(str, st);
	}

	return 0;
}