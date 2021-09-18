#include <iostream>

using namespace std;
int N;
int A[12] = { 0, };
int calc[4] = { 0, };
int minVal = 1000000000;
int maxVal = -1000000000;

void solve(int len, int* calc, int calc_result)
{
	if (len == N)
	{
		minVal = min(calc_result, minVal);
		maxVal = max(calc_result, maxVal);
	}
	else
	{
		if (calc[0] > 0)
		{
			calc[0]--;
			solve(len + 1, calc, calc_result + A[len]);
			calc[0]++;
		}
		if (calc[1] > 0)
		{
			calc[1]--;
			solve(len + 1, calc, calc_result - A[len]);
			calc[1]++;
		}
		if (calc[2] > 0)
		{
			calc[2]--;
			solve(len + 1, calc, calc_result * A[len]);
			calc[2]++;
		}
		if (calc[3] > 0)
		{
			calc[3]--;
			solve(len + 1, calc, calc_result / A[len]);
			calc[3]++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> calc[i];
	}

	solve(1, calc, A[0]);

	cout << maxVal << endl;
	cout << minVal << endl;

	return 0;
}