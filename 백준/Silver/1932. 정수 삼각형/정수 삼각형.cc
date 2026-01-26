#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<vector<int>> v(N, vector<int>());

	int tmp;
	cin >> tmp;
	v[0].push_back(tmp);
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 0; j < v[i].size() - 1; j++)
		{
			v[i - 1][j] += max(v[i][j], v[i][j + 1]);
		}
	}
	cout << v[0][0];
	return 0;
}