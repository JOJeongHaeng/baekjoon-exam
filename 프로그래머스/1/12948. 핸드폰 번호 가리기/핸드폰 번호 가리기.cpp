#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string text;
    for(int i = 0; i < phone_number.length() - 4; i++)
    {
        text += "*";
    }
    phone_number.replace(phone_number.begin(), phone_number.end()-4, text);
    return phone_number;
}