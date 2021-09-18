#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int N;
int M;
int r, c, d;
int MAP[MAX][MAX] = { 0, };
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int ans = 0;

void Input()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> MAP[row][col];
		}
	}
}

void Solve(int row, int col, int dir)
{
	if (MAP[row][col] == 0)
	{
		MAP[row][col] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++)
	{
		int nd = dir - 1 - i;
		if (nd < 0)
		{
			nd = nd + 4;
		}
		int nr = row + dr[nd];
		int nc = col + dc[nd];
		if (MAP[nr][nc] == 1 || MAP[nr][nc] == 2)
		{
			continue;
		}

		if (MAP[nr][nc] == 0)
		{
			Solve(nr, nc, nd);
		}
	}

	int nd = dir + 2;
	if (nd >= 4)
	{
		nd = nd - 4;
	}
	int nr = row + dr[nd];
	int nc = col + dc[nd];

	if (MAP[nr][nc] == 1)
	{
		cout << ans;
		exit(0);
	}

	Solve(nr, nc, dir);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve(r, c, d);

	return 0;
}