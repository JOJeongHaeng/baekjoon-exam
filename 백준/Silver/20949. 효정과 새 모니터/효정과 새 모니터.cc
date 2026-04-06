#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int n;
float x, y;
vector<pair<float, int>> v;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		v.push_back({ (x * x) + (y * y), i });
	}

	sort(v.begin(), v.end(), [](pair<float, int>& p1, pair<float, int>& p2) {
		if (p1.first == p2.first) return p1.second < p2.second;
		return p1.first > p2.first;
		});

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << '\n';
	}
	return 0;
}