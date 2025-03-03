#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> num;
    int piece = 6;
    for(int i=2; i<=n; i++){
        if(n%i == 0 && piece%i == 0){
            num.push_back(i);
            while(n%i == 0 && piece%i == 0){
                n/=i;
                piece/=i;
            }
        }
    }
    int answer = 1;
    for(int i:num) answer*=i;
    return (answer*n*piece)/6;
}