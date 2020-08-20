#include <iostream>
using namespace std;

int A, B, C;
int ans[3] = { 0,0,0 };

int main(void)
{
	cin >> A >> B >> C;

	if (A >= B)
	{
		ans[0] += 1;
	}
	else
	{
		ans[1] += 1;
	}

	if (B >= C)
	{
		ans[1] += 1;
	}
	else
	{
		ans[2] += 1;
	}

	if (A >= C)
	{
		ans[0] += 1;
	}
	else
	{
		ans[2] += 1;
	}

	for (int i = 0; i < 3; i++)
	{
		if (ans[i] == 1)
		{
			if (i == 0) {
				cout << A;
			}
			else if (i == 1)
			{
				cout << B;
			}
			else
			{
				cout << C;
			}
		}
	}

	return 0;
}