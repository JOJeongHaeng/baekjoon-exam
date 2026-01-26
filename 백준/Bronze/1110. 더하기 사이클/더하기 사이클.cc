#include <iostream>

using namespace std;

int calcul(int N)
{
	int tmp, sum, right;
	if (N < 10) tmp = N * 10;
	else tmp = N;
	sum = (tmp / 10) + (tmp % 10);
	right = N % 10;\
	return (right * 10) + (sum % 10);
}

int main()
{
	int N, Cnt = 0;
	cin >> N;
	int NewNum = N;
	do
	{
		NewNum = calcul(NewNum);
		Cnt++;
	}
	while (N != NewNum);
	
	cout << Cnt;
	return 0;
}