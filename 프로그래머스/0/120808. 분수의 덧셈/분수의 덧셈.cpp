#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> tmp;
    int min_n = min(denom1, denom2);
    int tmp1 = denom1; int tmp2 = denom2;
    for(int i=2; i<=min_n; i++){
        if(denom1%i == 0 && denom2%i == 0){
            while(tmp1%i == 0 && tmp2%i == 0){
                tmp.push_back(i);
                tmp1/=i;
                tmp2/=i;
            }
        }
    }
    tmp.push_back(tmp1);
    tmp.push_back(tmp2);
    
    int denom = 1;
    for(int i: tmp) denom*=i;
    
    int numer = (numer1*(denom/denom1))+(numer2*(denom/denom2));
    for(int i=2; i<=numer; i++){
        if(numer%i == 0 && denom%i == 0){
            while(numer%i == 0 && denom%i == 0){
                numer/=i;
                denom/=i;
            }
        }
    }
    vector<int> answer = {numer, denom};
    return answer;
}