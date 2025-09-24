#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int x = brown/2+2-3, y = 3;
    while(x>=y)
    {
        if(x*y == brown+yellow) return answer = {x, y};
        else y++, x--;
    }
    
}