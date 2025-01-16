#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string s1 = to_string(a)+to_string(b);
    string s2 = to_string(b)+to_string(a);
    int i1 = stoi(s1);
    int i2 = stoi(s2);
    return (i1>i2) ? i1 : i2;
}