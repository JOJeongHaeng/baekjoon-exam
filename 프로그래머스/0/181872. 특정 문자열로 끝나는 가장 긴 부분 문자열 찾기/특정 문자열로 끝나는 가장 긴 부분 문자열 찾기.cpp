#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString, string pat) {
    reverse(myString.begin(), myString.end());
    reverse(pat.begin(), pat.end());
    myString = myString.substr(myString.find(pat));
    reverse(myString.begin(), myString.end());
    return myString;
}