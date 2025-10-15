#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int count = citations.size();
    while(count != 0)
    {
        int tmp = 0;
        for(int i : citations)
        {
            if(i >= count) tmp++;
        }
        if(tmp >= count) break;
        else count--;
    }
    
    return count;
}