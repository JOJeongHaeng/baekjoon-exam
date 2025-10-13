#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) 
{
    unordered_set<int> us;
    int n = elements.size();
    while(n>0)
    {
        for(int i = 0; i<elements.size(); i++)
        {
            int sum = 0;
            for(int j = i; j<i+n; j++)
            {
                if(j < elements.size()) sum+=elements[j];
                else sum+= elements[j-elements.size()];
            }
            us.insert(sum);
        }
        n--;
    }
    int answer = us.size();
    return answer;
}