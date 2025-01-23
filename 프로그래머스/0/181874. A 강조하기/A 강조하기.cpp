#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    for(char& c:myString){
        if (c == 'a') c='A';
    }
    return myString;
}