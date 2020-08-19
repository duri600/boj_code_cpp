#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 20

int A, B;
queue<int> q;
void processing()
{
	int moc, spare;
	int count = 0;
	spare = A % B;
	moc = A / B;
	q.push(moc);
	while (spare != 0)
	{
		count++;
		spare = spare * 10;
		moc = spare / B;
		spare = spare % B;
		q.push(moc);
		if (count >= MAX_SIZE)
		{
			break;
		}
	}
}

int main(void)
{
	int flag = 1;
	cin >> A >> B;

	processing();

	cout << q.front();
	q.pop();
	while (!q.empty())
	{
		if (flag == 1)
		{
			cout << ".";
			flag = 0;
		}
		cout << q.front();
		q.pop();
	}

	return 0;
}