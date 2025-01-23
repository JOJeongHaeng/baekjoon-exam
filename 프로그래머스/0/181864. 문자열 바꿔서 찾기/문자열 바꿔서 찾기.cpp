#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for (char& c:myString){
        if (c == 'A') c ='B';
        else c = 'A';
    }
    return (myString.find(pat) != string::npos);
}