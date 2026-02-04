#include <iostream>
#include <stack>

using namespace std;

int main()
{

	int N;
	cin >> N;

	stack<int> st;
	stack<int> r_st;
	string answer = "";
	for (int i = N; i >= 1; i--)
	{
		r_st.push(i);
	}
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;

		while (!r_st.empty())
		{
			if (r_st.top() <= tmp)
			{
				st.push(r_st.top());
				answer += "+\n";
				r_st.pop();
			}
			else break;
		}
		if (!st.empty() && st.top() == tmp)
		{
			answer += "-\n";
			st.pop();
		}
		else
		{
			answer = "NO\n";
			break;
		}
	}
	cout << answer;
	return 0;
}