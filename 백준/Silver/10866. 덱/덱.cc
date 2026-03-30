#include <iostream>
#include <string>

#define MAX 10001

using namespace std;

int deck[MAX];
int idx = 0, n, tmp;

void push_front(int num)
{
	for (int i = idx; i > 0; i--)
	{
		deck[i] = deck[i - 1];
	}
	deck[0] = num;
	idx++;
}

void push_back(int num)
{
	deck[idx] = num;
	idx++;
}

void pop_front()
{
	if (idx == 0)
	{
		cout << -1 << '\n';
		return;
	}
	cout << deck[0] << '\n';
	for (int i = 0; i < idx; i++)
	{
		deck[i] = deck[i + 1];
	}
	idx--;
}

void pop_back()
{
	if (idx == 0)
	{
		cout << -1 << '\n';
		return;
	}
	cout << deck[--idx] << '\n';
}

void size()
{
	cout << idx << '\n';
}

void empty()
{
	cout << ((idx != 0) ? 0 : 1) << '\n';
}

void front()
{
	if (idx == 0) cout << -1 << '\n';
	else cout << deck[0] << '\n';
}

void back()
{
	if (idx == 0) cout << -1 << '\n';
	else cout << deck[idx - 1] << '\n';
}

void calculator(string str)
{
	if (str == "push_front")
	{
		cin >> tmp;
		push_front(tmp);
	}
	else if (str == "push_back")
	{
		cin >> tmp;
		push_back(tmp);
	}
	else if (str == "pop_front")
	{
		pop_front();
	}
	else if (str == "pop_back")
	{
		pop_back();
	}
	else if (str == "size")
	{
		size();
	}
	else if (str == "empty")
	{
		empty();
	}
	else if (str == "front")
	{
		front();
	}
	else if (str == "back")
	{
		back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		calculator(str);
	}
	return 0;
}