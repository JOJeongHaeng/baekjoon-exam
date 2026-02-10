#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		stack<char> st;
		bool check = false;

		if (str == ".") break;

		string answer = "yes";
		for (char c : str)
		{
			if (c == '(') st.push('(');
			else if (c == '[') st.push('[');
			else if (c == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					answer = "no";
					check = true;
				}
				else if(st.top() == '(')
				{
					st.pop();
				}
			}
			else if (c == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					answer = "no";
					check = true;
				}
				else if (st.top() == '[')
				{
					st.pop();
				}
			}
			if (check) break;
		}
		if (!st.empty()) answer = "no";
		cout << answer << '\n';
	}

	return 0;
}