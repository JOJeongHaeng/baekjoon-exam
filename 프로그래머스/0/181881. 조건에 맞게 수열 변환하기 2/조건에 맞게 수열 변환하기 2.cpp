#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int x =0;
    while(true){
        vector<int>temparr = arr;
        for (int& i : arr){
            if(i&1==0 && 50<=i) i/=2;
            else if(i&1==1 && i<50) i=i*2+1;
        }
        if (arr==temparr){
            return x;
        }
        else ++x;
    }
}