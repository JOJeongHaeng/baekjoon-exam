#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> us[8];
    
    int tmp = 0;
    for(int i = 0; i<8; i++)
    {
        tmp = 10*tmp + N;
        us[i].insert(tmp);
    }
    
    for(int i = 1; i<8; i++)
    {
        for(int j = 0; j<i; j++)
        {
            for(int a : us[j])
            {
                for(int b : us[i - j - 1])
                {
                    us[i].insert(a + b);
                    us[i].insert(a - b);
                    us[i].insert(a * b);
                    if(b != 0)
                        us[i].insert(a / b);
                }
            }
        }
    }
    
    for(int i = 0; i<8; i++)
    {
        if(us[i].find(number) != us[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}