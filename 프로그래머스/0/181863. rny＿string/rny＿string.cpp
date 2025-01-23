#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    while(rny_string.find("m")!=string::npos){
        rny_string.replace(rny_string.find("m"), 1, "rn");
    }
    return rny_string;
}