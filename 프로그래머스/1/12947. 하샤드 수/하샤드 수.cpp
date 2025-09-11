#include <string>
#include <vector>

using namespace std;

int sum(int x)
{
    int result = 0;
    while(x/10 != 0)
    {
        result+= x%10;
        x/=10;
    }
    result += x;
    return result;
}

bool solution(int x) {
    int num = sum(x);
    return x%num == 0 ? true : false;
}