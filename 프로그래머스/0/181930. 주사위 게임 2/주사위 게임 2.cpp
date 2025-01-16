#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    int score = 0;
    if (a!=b && a!=c && b!=c){
        score = a+b+c;
    }
    else if (a==b && a==c){
        score = (a+b+c)*(pow(a,2)+pow(b,2)+pow(c,2))*((pow(a,3)+pow(b,3)+pow(c,3)));
    }
    else{
        score = (a+b+c)*(pow(a,2)+pow(b,2)+pow(c,2));
    }
    return score;
}