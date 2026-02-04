#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K; 
	vector<int> v;
	vector<int> answer;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}

	int now = K - 1;
	while (!v.empty())
	{
		if (now >= v.size()) now %= v.size();
		answer.push_back(v[now]);
		v.erase(v.begin() + now);
		now += K - 1;
	}

	cout << '<';
	for (int i = 0; i < answer.size(); i++)
	{
		if (i == answer.size() - 1) cout << answer[i] << ">";
		else cout << answer[i] <<", ";
	}

	return 0;
}