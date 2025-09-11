#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int last = arr[0];
    answer.push_back(last);
    for(int i : arr)
    {
        if(last != i)
        {
            answer.push_back(i);
            last = i;
        }
    }
    return answer;
}