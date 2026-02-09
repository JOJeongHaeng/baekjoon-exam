#include <iostream>

using namespace std;

int mx_dp[2][3];
int mn_dp[2][3];

int main()
{
	int N;
	cin >> N;

	int a, b, c;
	int K = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;

		mn_dp[K][0] = a + min(mn_dp[1 - K][0], mn_dp[1 - K][1]);
		mn_dp[K][1] = b + min(min(mn_dp[1 - K][0], mn_dp[1 - K][1]), mn_dp[1 - K][2]);
		mn_dp[K][2] = c + min(mn_dp[1 - K][1], mn_dp[1 - K][2]);

		mx_dp[K][0] = a + max(mx_dp[1 - K][0], mx_dp[1 - K][1]);
		mx_dp[K][1] = b + max(max(mx_dp[1 - K][0], mx_dp[1 - K][1]), mx_dp[1 - K][2]);
		mx_dp[K][2] = c + max(mx_dp[1 - K][1], mx_dp[1 - K][2]);

		K = 1 - K;
	}

	cout << max(max(mx_dp[1 - K][0], mx_dp[1 - K][1]), mx_dp[1 - K][2]) << " " << min(min(mn_dp[1 - K][0], mn_dp[1 - K][1]), mn_dp[1 - K][2]);

	return 0;
}