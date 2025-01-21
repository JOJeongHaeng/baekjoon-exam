#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int nums[4] = {a, b, c, d};
    map<int, int> m;
    for (int n : nums){
        m[n] = ++m[n];
    }
    
    map<int, int>::iterator it = m.begin();
    map<int, int>::iterator it_n = next(m.begin());
    
    if (m.size() == 1){
        answer = 1111*a;
    }
    else if (m.size() == 2){
        if (it->second == it_n->second){
            answer = ((it->first)+(it_n->first))*abs((it->first)-(it_n->first));
        }
        else{
            int p;
            int q;
            if (it->second == 3){
                p = (it->first);
                q = (it_n->first);
            }
            else{
                p = (it_n->first);
                q = (it->first);
            }
            answer = pow(10*p+q,2);
        }
    }
    else if (m.size() == 3){
        for (; it != m.end(); it++){
            if (it->second > 1){
                m.erase(it->first);
            }
        }
        answer = (m.begin()->first)*(next(m.begin())->first);
    }
    else{
        answer = min({a,b,c,d});
    }
    return answer;
}