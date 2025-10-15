#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if(cacheSize == 0) return cities.size()*5;
    for(string tmp : cities)
    {
        string str;
        for(char c :tmp) str+=toupper(c);
        if(cache.size() < cacheSize)
        {
            if(find(cache.begin(), cache.end(), str) != cache.end())
            {
                cache.erase(find(cache.begin(), cache.end(), str));
                cache.push_back(str);
                answer++;
            }
            else 
            {
                cache.push_back(str);
                answer+=5;
            }
        }
        else
        {
            if(find(cache.begin(), cache.end(), str) != cache.end())
            {
                cache.erase(find(cache.begin(), cache.end(), str));
                cache.push_back(str);
                answer++;
            }
            else
            {
                cache.erase(cache.begin());
                cache.push_back(str);
                answer+=5;
            }
        }
    }
    return answer;
}