#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string tmp = "";
	int answer = 0;
	int sum = 0;
	bool flag = false;
	for (char c : str)
	{
		if (isdigit(c)) tmp += c;
		else if (c == '+')
		{
			if (flag)
			{
				sum += stoi(tmp);
				tmp = "";
			}
			else
			{
				answer += stoi(tmp);
				tmp = "";
			}
		}
		else
		{
			if (flag)
			{
				sum += stoi(tmp);
				tmp = "";
			}
			else
			{
				answer += stoi(tmp);
				tmp = "";
			}
			flag = true;
		}
	}
	if (flag) answer -= stoi(tmp);
	else answer += stoi(tmp);
	answer -= sum;
	cout << answer << '\n';
	
	return 0;
}