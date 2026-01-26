#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmpV;
		int tmp;
		for (int j = 0; j < 3; j++)
		{
			cin >> tmp;
			tmpV.push_back(tmp);
		}
		v.push_back(tmpV);
	}
	long long CostRGB[1001][3];
	
	CostRGB[0][0] = v[0][0];
	CostRGB[0][1] = v[0][1];
	CostRGB[0][2] = v[0][2];

	for (int i = 1; i < n; i++)
	{
		CostRGB[i][0] = v[i][0] + min(CostRGB[i - 1][1], CostRGB[i-1][2]);
		CostRGB[i][1] = v[i][1] + min(CostRGB[i - 1][0], CostRGB[i - 1][2]);
		CostRGB[i][2] = v[i][2] + min(CostRGB[i - 1][0], CostRGB[i - 1][1]);
	}

	cout << min(min(CostRGB[n - 1][0], CostRGB[n - 1][1]), CostRGB[n - 1][2]);
	return 0;
}