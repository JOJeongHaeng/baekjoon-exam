#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i : arr)
    {
        int a = answer;
        int b = i;
        while(answer != i)
        {
            answer > i ? i+=b : answer+=a;
        }
    }
    return answer;
}