#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantmap;
    for(int i = 0; i<want.size(); i++) wantmap[want[i]] = number[i];
    for(int i = 0; i<=discount.size()-10; i++)
    {
        unordered_map<string, int> compmap;
        for(int j = 0; j<10; j++)
        {
            compmap[discount[i+j]]++;
        }
        int count = 0;
        for(auto p : wantmap)
        {
            if(p.second == compmap[p.first]) count++;
            else break;
        }
        if(count == want.size()) answer++;
    }
    return answer;
}