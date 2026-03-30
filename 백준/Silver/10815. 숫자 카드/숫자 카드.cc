#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, tmp;
unordered_map<int, bool> deck;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		deck[tmp] = true;
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp;
		
		cout << deck[tmp] << ' ';
	}

	return 0;
}