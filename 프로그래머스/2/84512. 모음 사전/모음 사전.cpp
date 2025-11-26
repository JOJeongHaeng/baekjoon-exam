#include <string>
#include <vector>

using namespace std;

void dfs(const string& word, string AEIOU, string now, int& cnt, int& answer)
{
    if(word == now)
    {
        answer = cnt;
        return;
    }
    if(now.size() >= 5) return;
    for(char c : AEIOU)
    {
        cnt++;
        dfs(word, AEIOU, now+c, cnt, answer);
    }
}

int solution(string word) {
    int answer = 0;
    int count = 0;
    string AEIOU = "AEIOU";
    dfs(word, AEIOU, "", count, answer);
    return answer;
}