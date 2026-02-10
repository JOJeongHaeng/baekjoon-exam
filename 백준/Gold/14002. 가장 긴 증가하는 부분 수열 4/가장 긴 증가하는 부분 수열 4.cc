#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	vector<vector<int>> v(1001, vector<int>());
	
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		v[i].push_back(i);
	}

	int answer = 1;
	int idx = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
					if (dp[i] > answer)
					{
						answer = dp[i];
						idx = i;
					}
					v[i] = v[j];
					v[i].push_back(i);
				}
			}
		}
	}

	cout << dp[idx] << '\n';
	sort(v[idx].begin(), v[idx].end());
	for (int i : v[idx])
	{
		cout << arr[i] << " ";
	}
	return 0;
}