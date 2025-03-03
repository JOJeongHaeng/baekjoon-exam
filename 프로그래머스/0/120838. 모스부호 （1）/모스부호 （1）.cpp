#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) {
    map<string, char> morse {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.",'c'}, {"-..",'d'}, {".",'e'},
        {"..-.",'f'}, {"--.",'g'}, {"....",'h'}, {"..",'i'}, {".---",'j'},
        {"-.-",'k'}, {".-..",'l'}, {"--",'m'}, {"-.",'n'}, {"---",'o'},
        {".--.",'p'}, {"--.-",'q'}, {".-.",'r'}, {"...",'s'}, {"-",'t'},
        {"..-",'u'}, {"...-",'v'}, {".--",'w'}, {"-..-",'x'}, {"-.--",'y'},
        {"--..",'z'}
    };
    string answer = "";
    string tmp = "";
    for(char c : letter){
        if(c == ' ') {
            answer+= morse[tmp];
            tmp = "";
        }
        else tmp+=c;
    }
    answer+= morse[tmp];
    return answer;
}