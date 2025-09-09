#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> stu1 = { 1, 2, 3, 4, 5 };
    vector<int> stu2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> stu3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int s1 = 0, s2 = 0, s3 = 0;
    
    for(int i = 0; i<answers.size(); i++)
    {
        if(stu1[i%5] == answers[i]) s1++;
        if(stu2[i%8] == answers[i]) s2++;
        if(stu3[i%10] == answers[i]) s3++;
    }
    
    if (s1 == s2 && s2 == s3) answer = {1, 2, 3};
    else if (s1 == s2)
    {
        if(s1>s3) answer = {1, 2};
        else answer = {3};
    }
    else if (s2 == s3)
    {
        if(s1<s2) answer = {2, 3};
        else answer = {1};
    }
    else if (s1 == s3)
    {
        if(s1>s2) answer = {1, 3};
        else answer = {2};
    }
    else
    {
        if(max(max(s1, s2), s3) == s1) answer = {1};
        else if(max(max(s1, s2), s3) == s2) answer = {2};
        else answer = {3};
    }
    
    return answer;
}