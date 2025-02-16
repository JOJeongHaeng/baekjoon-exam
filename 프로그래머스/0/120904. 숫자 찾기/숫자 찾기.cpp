#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    vector<int> numlist;
    while(num>0){
        numlist.push_back(num%10);
        num/=10;
    }
    for (int i=0; i<numlist.size(); i++){
        if(numlist[i] == k){
            answer = numlist.size()-i;
        }
    }
    return answer;
}