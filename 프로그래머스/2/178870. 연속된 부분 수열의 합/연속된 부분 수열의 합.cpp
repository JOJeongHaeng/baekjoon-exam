#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int Size = sequence.size();
    vector<int> answer = {0, Size};
    int min = Size;
    int start = 0;
    int end = 0;
    int arr[Size];
    int tmp = 0;
    
    for(int i = 0; i<Size; i++)
    {
        tmp+=sequence[i];
        arr[i] = tmp;
    }
    
    while((start < Size) && (end < Size))
    {
        int sum = 0;
        if(start == 0)
        {
            sum = arr[end];
        }
        else
        {
            sum = arr[end] - arr[start-1];
        }
        
        if(sum == k)
        {
            if(min > end-start)
            {
                min = end-start;
                answer[0] = start;
                answer[1] = end;
            }
            end++;
        }
        else if(sum > k) start++;
        else if(sum < k) end++;
    }
    
    return answer;
}