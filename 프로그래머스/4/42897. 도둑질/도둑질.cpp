#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int dp1[1000001];
    int dp2[1000001];
    int m_s = money.size() - 1;
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i = 2; i < m_s; i++)
    {
        dp1[i] = max(dp1[i-1], money[i] + dp1[i - 2]);
        dp2[i] = max(dp2[i-1], money[i] + dp2[i - 2]);
    }
    dp2[m_s] = max(dp2[m_s - 1], money[m_s] + dp2[m_s - 2]);
    answer = max(dp1[m_s - 1], dp2[m_s]);
    return answer;
}