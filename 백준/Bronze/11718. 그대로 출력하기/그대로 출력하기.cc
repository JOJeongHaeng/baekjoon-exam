#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	while (str != "")
	{
		cout << str << endl;
		getline(cin, str);
	}
	
	return 0;
}