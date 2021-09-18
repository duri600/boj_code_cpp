#include <iostream>

#define MAX 1000001
using namespace std;
int A[MAX] = { 0, };

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
	}

	int B, C;
	cin >> B >> C;

	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		A[i] = A[i] - B;
		ans++;
		if (A[i] > 0)
		{
			if (A[i] % C == 0)
			{
				ans = ans + (A[i] / C);
			}
			else
			{
				ans = ans + (A[i] / C) + 1;
			}
		}
	}

	cout << ans;
	return 0;
}