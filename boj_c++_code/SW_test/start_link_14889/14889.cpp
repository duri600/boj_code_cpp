#include <iostream>
#define MAX 21
using namespace std;

int N;
int MAP[MAX][MAX] = { 0, };
int visit[MAX] = { 0, };
int minVal = 1000000000;

void solve(int len, int pos)
{
	if (len == N / 2)
	{
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i] == 1 && visit[j] == 1)
				{
					start += MAP[i][j];
				}
				if (visit[i] == 0 && visit[j] == 0)
				{
					link += MAP[i][j];
				}
			}
		}
		int diff = abs(start - link);
		minVal = min(minVal, diff);
	}

	for (int i = pos; i < N; i++)
	{
		visit[i] = 1;
		solve(len + 1, i + 1);
		visit[i] = 0;
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
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	solve(0, 1);

	cout << minVal << endl;

	return 0;
}