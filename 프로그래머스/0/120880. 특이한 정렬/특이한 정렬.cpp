#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    int tmp;
    sort(numlist.begin(), numlist.end());
    for(int i=0; i<numlist.size(); i++){
        int dis = 10001;
        for(int j=0; j<numlist.size(); j++){
            if(abs(numlist[j]-n) <= dis) {
                dis = abs(numlist[j]-n);
                tmp = numlist[j];
            }
        }
        answer.push_back(tmp);
        replace(numlist.begin(), numlist.end(), tmp, 20001);
    }
    return answer;
}