#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int num = 0;
    for(int i = 1; i<=n; i++) num+=i;
    vector<int> answer(num, 0);
    char dir = 'D';
    int count = 0;
    int idx = 0;
    
    for(int i = 1; i<=num; i++)
    {
        answer[idx] = i;
        switch(dir)
        {
            case 'D':
            {
                count++;
                idx+=count;
                if(idx >= num || answer[idx])
                {
                    idx-=count;
                    idx++;
                    dir = 'R';
                }
                break;
            }
            case 'R':
            {
                idx++;
                if(idx >= num || answer[idx])
                {
                    idx--;
                    idx-= count;
                    dir = 'U';
                }
                break;
            }
            case 'U':
            {
                count--;
                idx-=count;
                if(idx < 0 || answer[idx])
                {
                    idx+= count * 2;
                    dir = 'D';
                }
                break;
            }
        }
    }
    return answer;
}