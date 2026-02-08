#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int mx = 0;
	char mxC = 'A';
	unordered_map<char, int> um;
	for (char c : str)
	{
		c = toupper(c);
		um[c]++;
		if (um[c] > mx)
		{
			mx = um[c];
			mxC = c;
		}
	}
	
	for (pair<char, int> p : um)
	{
		if (p.second == mx && p.first != mxC)
		{
			cout << "?" << '\n';
			return 0;
		}
	}
	cout << mxC << '\n';
	return 0;
}