#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	stack<int> st;
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		if (tmp) st.push(tmp);
		else
		{
			if (st.empty()) continue;
			else st.pop();
		}
	}
	int sum = 0;
	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}

	cout << sum << endl;
	return 0;
}