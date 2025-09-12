#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int vsize = ingredient.size();
    for(int i = 0; i<=vsize-4; i++)
    {
        if(ingredient[i] == 1 && ingredient[i+1] == 2 && ingredient[i+2] == 3 && ingredient[i+3] == 1) 
        {
            answer++;
            ingredient.erase(ingredient.begin()+i, ingredient.begin()+i+4);
            i-5 <= -1 ? i=-1: i-=5;
            vsize-=4;
        }
    }
    return answer;
}