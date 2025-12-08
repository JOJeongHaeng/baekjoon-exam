#include <string>
#include <vector>

using namespace std;

int gcd(int A, int B)
{
    return A%B == 0 ? B : gcd(B, A%B);
}

bool check(int min, vector<int> array)
{
    for(int i = 0; i<array.size(); i++)
    {
        if(array[i]%min == 0) return false;
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int minA = arrayA[0];
    int minB = arrayB[0];
    
    for(int i = 1; i<arrayA.size(); i++)
    {
        minA = gcd(minA, arrayA[i]);
        minB = gcd(minB, arrayB[i]);
    }
    
    minA = check(minA, arrayB) ? minA : 0;
    minB = check(minB, arrayA) ? minB : 0;
    
    return minA > minB ? minA : minB;
}