#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(players.size(), 0);
    for(int i = 0; i<players.size(); i++)
    {
        if(server[i] < players[i]/m)
        {
            int tmp = players[i]/m-server[i];
            answer += tmp;
            for(int j = i; j<i+k; j++)
            {
                if(players.size() == j) break;
                server[j] = server[j] + tmp;
            }
        }
    }
    return answer;
}