#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxw = 0; int maxh = 0;
    for(int i = 0; i<sizes.size(); i++)
    {
        if(sizes[i][0]>maxw) maxw = sizes[i][0];
        if(sizes[i][1]>maxh) maxh = sizes[i][1];
    }
    if(maxw > maxh)
    {
        for(int i = 0; i<sizes.size(); i++)
        {
            if(sizes[i][0]<sizes[i][1])
            {
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
        }
    }
    else
    {
        for(int i = 0; i<sizes.size(); i++)
        {
            if(sizes[i][0]>sizes[i][1])
            {
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
        }
    }
    maxw = 0; maxh = 0;
    for(int i = 0; i<sizes.size(); i++)
    {
        if(sizes[i][0]>maxw) maxw = sizes[i][0];
        if(sizes[i][1]>maxh) maxh = sizes[i][1];
    }
    return maxw * maxh;
}