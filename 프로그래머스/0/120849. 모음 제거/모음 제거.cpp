#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for(char c : my_string){
        if(find(vowels.begin(), vowels.end(), c) == vowels.end()) answer+=c;
    }
    return answer;
}