#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int left[1000001];
    int right[1000001];
    int visit[1000001];
    
    int count = 0;
    
    for(int i = 0; i < topping.size()-1; i++)
    {
        int tmp = topping[i];
        if(visit[tmp] == 0)
        {
            visit[tmp] = 1;
            count++;
        }
        left[i] = count;
    }
    
    count = 0;
    fill(&visit[0], &visit[0]+1000001, 0);
    
    for(int i = topping.size()-1; i >= 0; i--)
    {
        int tmp = topping[i];
        if(visit[tmp] == 0)
        {
            visit[tmp] = 1;
            count++;
        }
        right[i] = count;
    }
    
    for(int i = 0; i < topping.size()-2; i++)
    {
        if(left[i] == right[i+1]) answer++;
    }
    return answer;
}