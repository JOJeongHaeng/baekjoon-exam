#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> um;
    int idx = 0;
    char check = words[0][0];
    for(string word : words)
    {
        um[word]++;
        if(um[word] > 1) break;
        else if(check != word[0]) break;
        ++idx;
        
        check = word.back();
    }
    if((idx/n)+1 > words.size()/n) return {0, 0};
    answer = {(idx%n)+1, (idx/n)+1};
    return answer;
}