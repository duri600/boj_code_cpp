#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int C[100];
void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> C[i];
	}
}

int Processing() {
	int sum = 0;
	int sum_max = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = C[i] + C[j] + C[k];
				if (sum == M) {
					return M;
				}
				else if (sum < M)
				{
					sum_max = max(sum,sum_max);
				}
			}
		}
	}
	return sum_max;
}

int main(void) {
	InputData();

	int ans = Processing();

	cout << ans << endl;

	return 0;
}