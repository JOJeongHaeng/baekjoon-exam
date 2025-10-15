#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    for(vector<string> v : clothes)
    {
        um[v[1]]++;
    }
    if(um.size() == 1) answer = clothes.size();
    else
    {
        for(auto iter : um)
        {
            answer *= iter.second+1;
        }
        answer--;
    }
    return answer;
}