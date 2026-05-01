#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000001];
int idx = 0;

void calculation(string str)
{
    switch(str[0])
    {
        case 'I':
        {
            arr[idx] = stoi(str.substr(2, str.size() - 2));
            idx++;
            break;
        }
        case 'D':
        {
            if(idx == 0) break;
            else if(str[2] == '-')
            {
                sort(arr, arr + idx, greater<int>());
                idx--;
            }
            else
            {
                sort(arr, arr + idx);
                idx--;
            }
            break;
        }
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string str : operations)
    {
        calculation(str);
    }
    if(idx == 0) return {0, 0};
    
    sort(arr, arr + idx);
    answer.push_back(arr[idx - 1]);
    answer.push_back(arr[0]);
    
    return answer;
}