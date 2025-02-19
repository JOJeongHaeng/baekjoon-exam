#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    vector<int> bv;
    for(int i=2; i<=a; i++){
        while(a%i == 0 && b%i == 0){
            a/=i;
            b/=i;
        }
    }
    for(int i=2; i<=b; i++){
        while(b%i == 0){
            bv.push_back(i);
            b/=i;
        }
    }
    for(int i : bv){
        if(i!=2 && i !=5) return 2;
    }
    return 1;
}