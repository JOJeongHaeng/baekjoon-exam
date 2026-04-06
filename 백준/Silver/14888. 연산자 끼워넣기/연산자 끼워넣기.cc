#include <iostream>
#include <vector>

#define MAX 11

using namespace std;

int n, MX = -1000000000, MN = 1000000000;
int arr[MAX];
char oper[4] = { '+', '-', '*', '/' };
bool visit[MAX - 1];
vector<char> v;

void INPUT()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int tmp;
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			v.push_back(oper[i]);
		}
	}
}

void f(int cnt, int num)
{
	if (cnt == n)
	{
		if (MX < num) MX = num;
		if (MN > num) MN = num;
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			if (v[i] == '+')
			{
				f(cnt + 1, num + arr[cnt]);
			}
			else if (v[i] == '-')
			{
				f(cnt + 1, num - arr[cnt]);
			}
			else if (v[i] == '*')
			{
				f(cnt + 1, num * arr[cnt]);
			}
			else
			{
				f(cnt + 1, num / arr[cnt]);
			}
			visit[i] = false;
		}
	}
}

int main()
{
	INPUT();
	f(1, arr[0]);
	cout << MX << '\n' << MN;
	return 0;
}