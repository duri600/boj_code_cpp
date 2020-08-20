#include <iostream>
using namespace std;

int N;

bool checking(int n)
{
	if (n < 100) {
		return true;
	}

	int a, b, c;
	c = n % 10;
	b = (n / 10) % 10;
	a = (n / 100) % 10;
	if ((a - b) == (b - c))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	int count = 0;
	cin >> N;
	if (N == 1000)
	{
		N = N - 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (checking(i))
		{
			count++;
		}
	}
	cout << count;

	return 0;
}