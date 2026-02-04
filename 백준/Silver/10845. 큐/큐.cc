#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int arr[10003];
int idx = 0;

void Push(int X) { arr[idx++] = X; }
void Pop()
{
	if (idx)
	{
		cout << arr[0] << endl;
		for (int i = 1; i < idx; i++)
		{
			arr[i - 1] = arr[i];
		}
		idx--;
	}
	else cout << -1 << endl;
}
void Size() { cout << idx << endl; }
void Empty() { cout << (idx ? 0 : 1) << endl; }
void Front() { cout << (idx ? arr[0] : -1) << endl; }
void Back() { cout << (idx ? arr[idx - 1] : -1) << endl; }


int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int tmp;
			cin >> tmp;
			Push(tmp);
		}
		else if (str == "pop") Pop();
		else if (str == "size") Size();
		else if (str == "empty") Empty();
		else if (str == "front") Front();
		else if (str == "back") Back();
	}

	return 0;
}