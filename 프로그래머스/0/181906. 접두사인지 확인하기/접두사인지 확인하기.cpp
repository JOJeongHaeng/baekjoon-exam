#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    if (is_prefix.size() > my_string.size()) return 0;
    return my_string.substr(0, is_prefix.size()) == is_prefix;
}