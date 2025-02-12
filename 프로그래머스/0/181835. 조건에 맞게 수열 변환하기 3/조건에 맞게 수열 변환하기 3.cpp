#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if (k%2==0) for(int& i : arr) i+=k;
    else for(int& i : arr) i*=k;
    return arr;
}