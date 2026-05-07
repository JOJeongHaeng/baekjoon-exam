#include <vector>
#include <string>

using namespace std;

int solution(vector<string> arr)
{
    int max_dp[102][102] = {0, };
    int min_dp[102][102] = {0, };
    int n_size = arr.size() / 2 + 1;
    
    int answer = -1;
    for(int i = 0; i<n_size; i++)
    {
        for(int j = 0; j<n_size; j++)
        {
            if(i == j)
            {
                max_dp[i][j] = stoi(arr[i * 2]);
                min_dp[i][j] = stoi(arr[i * 2]);
            }
            else
            {
                max_dp[i][j] = -1001001;
                min_dp[i][j] = 1001001;
            }
        }
    }
    
    for(int dif = 1; dif < n_size; dif++)
    {
        for(int i = 0; i <n_size - dif; i++)
        {
            int j = dif + i;
            for(int k = i; k < j; k++)
            {
                if(arr[k * 2 + 1] == "+")
                {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k + 1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k + 1][j]);
                }
                else
                {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k + 1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k + 1][j]);
                }    
            }
        }
    }
    answer = max_dp[0][n_size - 1];
    return answer;
}