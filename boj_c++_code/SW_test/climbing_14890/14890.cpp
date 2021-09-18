#include <iostream>
#include <vector>
#define MAX 101
#define MAX2 202
using namespace std;

int N, L;
int MAP[MAX2][MAX] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[N + i][j] = MAP[j][i];
		}
	}
	
	int count = 0;
	int i, j;
	int ret = 0;
	for (i = 0; i < 2 * N; i++)
	{
		count = 1;
		for (j = 0; j < N - 1; j++)
		{
			if (MAP[i][j] == MAP[i][j + 1]) // 평지
			{
				count++;
			}
			else if (MAP[i][j] + 1 == MAP[i][j + 1] && count >= L) // 오르막
			{
				count = 1;
			}
			else if (MAP[i][j] - 1 == MAP[i][j + 1] && count >= 0) // 내리막
			{
				count = 1 - L;
			}
			else
			{
				break;
			}
		}
		if (j == (N - 1) && count >= 0)
		{
			++ret;
		}
	}

	cout << ret << endl;

	return 0;
}