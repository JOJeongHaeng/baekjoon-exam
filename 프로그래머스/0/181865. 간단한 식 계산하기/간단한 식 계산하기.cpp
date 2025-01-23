#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int ln = 0;
    int rn = 0;
    string tmp;
    tmp = binomial.substr(0, binomial.find(" "));
    ln = stoi(tmp);
    binomial = binomial.substr(binomial.find(" ")+1, -1);
    rn = stoi(binomial.substr(binomial.find(" ")+1, -1));
    string FBO = binomial.substr(0, binomial.find(" "));
    if (FBO == "+") return ln+rn;
    else if (FBO == "-") return ln-rn;
    else if (FBO == "*") return ln*rn;
}