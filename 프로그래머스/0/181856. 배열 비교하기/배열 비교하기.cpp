#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int l_s = arr1.size(); int r_s = arr2.size();
    if (l_s < r_s) return -1;
    else if (r_s < l_s) return 1;
    int lsum = 0; int rsum = 0;
    for (int i=0; i<l_s; i++){
        lsum += arr1[i];
        rsum += arr2[i];
    }
    if (lsum<rsum) return -1;
    else if (rsum < lsum) return 1;
    else return 0;
}