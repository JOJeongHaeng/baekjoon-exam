#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> v;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}

	int K;
	cin >> K;
	K--;
	int idx = K;
	cout << "<";
	while (!(v.size() == 1))
	{
		if (idx < v.size())
		{
			cout << v[idx] << ", ";
			v.erase(v.begin() + idx);
			idx += K;
		}
		else
		{
			idx %= v.size();
		}
	}
	cout << v[0] << ">";
	return 0;
}