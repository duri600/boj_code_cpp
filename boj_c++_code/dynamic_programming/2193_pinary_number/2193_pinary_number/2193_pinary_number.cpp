#include <iostream>
using namespace std;

int N;
long long pNum[91];

long long Processing(int end)
{
	pNum[0] = 0;
	pNum[1] = 1;
	pNum[2] = 1;
	if (end > 2) 
	{
		for (int i = 3; i <= end; i++)
		{
			pNum[i] = pNum[i - 1] + pNum[i - 2];
		}
	}

	return pNum[end];
}

int main(void)
{
	cin >> N;

	long long ans = Processing(N);

	cout << ans;

	return 0;
}