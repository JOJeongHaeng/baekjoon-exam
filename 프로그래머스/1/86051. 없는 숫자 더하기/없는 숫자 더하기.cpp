#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> numv(10, 0);
    for(int num : numbers)
    {
        numv[num]++;
    }
    for(int i = 0; i<10; i++)
    {
        if (numv[i] == 0) answer+= i;
    }
    return answer;
}