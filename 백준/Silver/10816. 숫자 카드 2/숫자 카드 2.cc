#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	unordered_map<int, int> um;
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		um[tmp]++;
	}
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		cout << um[tmp] << " ";
	}

	return 0;
}