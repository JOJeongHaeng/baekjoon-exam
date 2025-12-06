#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(int i = 0; i<wires.size(); i++)
    {
        unordered_set<int> a;
        unordered_set<int> b;
        a.insert(wires[i][0]);
        b.insert(wires[i][1]);
        while(a.size()+b.size() != n)
        {
            for(int j = 0; j<wires.size(); j++)
            {
                if(i == j) continue;
                if(a.find(wires[j][0]) != a.end() || a.find(wires[j][1]) != a.end())
                {
                    a.insert(wires[j][0]);
                    a.insert(wires[j][1]);
                }
                else if(b.find(wires[j][0]) != b.end() || b.find(wires[j][1]) != b.end())
                {
                    b.insert(wires[j][0]);
                    b.insert(wires[j][1]);
                }
            }
        }
        int min = a.size() > b.size() ? a.size() - b.size() : b.size() - a.size();
        answer = answer > min ? min : answer;
    }
    return answer;
}