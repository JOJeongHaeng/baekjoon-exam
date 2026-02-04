#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	unordered_map<int, bool> um;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		um[tmp] = 1;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		cout << um[tmp] << '\n';
	}

	return 0;
}