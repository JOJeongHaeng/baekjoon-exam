#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for(int& i: numbers) i*=2;
    return numbers;
}