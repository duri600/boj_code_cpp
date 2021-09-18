#include <iostream>

using namespace std;

int N;
int T[16] = { 0, };
int P[16] = { 0, };
int ans = 0;

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

void Solve(int day, int sum)
{
	if (day == N + 1)
	{
		ans = max(ans, sum);
		return;
	}

	if (day + T[day] <= N + 1)
	{
		Solve(day + T[day], sum + P[day]);
	}
	if (day + 1 <= N + 1)
	{
		Solve(day + 1, sum);
	}
}

int main(void)
{
	Input();
	Solve(1, 0);

	cout << ans << endl;
	return 0;
}