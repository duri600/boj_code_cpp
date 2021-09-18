#include <iostream>
#define MAX 10
using namespace std;
char MAP[MAX][MAX];
pair<int, int> Red, Blue;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = { 0,0,-1,1 };
int ans = 99;

int Inverse_Dir(int dir)
{
	if (dir == 0)
	{
		return 1;
	}
	else if (dir == 1)
	{
		return 0;
	}
	else if (dir == 2)
	{
		return 3;
	}
	else if (dir == 3)
	{
		return 2;
	}
}

void dfs(int rr, int rc, int br, int bc, int cnt, int dir)
{
	if (cnt >= ans) return;
	if (cnt > 10) return;


	bool Red_Flag = false;
	bool Blue_Flag = false;
	int next_rr = rr + dr[dir];
	int next_rc = rc + dc[dir];
	while (1)
	{
		if (MAP[next_rr][next_rc] == '#') break;
		if (MAP[next_rr][next_rc] == 'O')
		{
			Red_Flag = true;
			break;
		}
		next_rr = next_rr + dr[dir];
		next_rc = next_rc + dc[dir];
	}
	next_rr = next_rr - dr[dir];
	next_rc = next_rc - dc[dir];

	int next_br = br + dr[dir];
	int next_bc = bc + dc[dir];
	while (1)
	{
		if (MAP[next_br][next_bc] == '#') break;
		if (MAP[next_br][next_bc] == 'O')
		{
			Blue_Flag = true;
			break;
		}
		next_br = next_br + dr[dir];
		next_bc = next_bc + dc[dir];
	}
	next_br = next_br - dr[dir];
	next_bc = next_bc - dc[dir];

	if (Blue_Flag == true) return;
	else
	{
		if (Red_Flag == true)
		{
			if (ans > cnt)
			{
				ans = cnt;
			}
			return;
		}
	}

	if (next_rr == next_br && next_rc == next_bc)
	{
		int r_dist;
		int b_dist;
		r_dist = abs(rr - next_rr) + abs(rc - next_rc);
		b_dist = abs(br - next_br) + abs(bc - next_bc);
		if (r_dist > b_dist)
		{
			next_rr = next_rr - dr[dir];
			next_rc = next_rc - dc[dir];
		}
		else
		{
			next_br = next_br - dr[dir];
			next_bc = next_bc - dc[dir];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		if (i == Inverse_Dir(dir)) continue;
		dfs(next_rr, next_rc, next_br, next_bc, cnt + 1, i);
	}

}

void solve()
{
	for (int i = 0; i < 4; i++)
	{
		dfs(Red.first, Red.second, Blue.first, Blue.second, 1, i);
	}
}

void Input()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 'R')
			{
				Red.first = i;
				Red.second = j;
				MAP[i][j] = '.';
			}
			else if (MAP[i][j] == 'B')
			{
				Blue.first = i;
				Blue.second = j;
				MAP[i][j] = '.';
			}
		}
	}
}

int main(void)
{
	Input();
	solve();

	if (ans > 10 || ans == 99)
	{
		ans = -1;
	}

	cout << ans << endl;

	return 0;
}