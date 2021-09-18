#include <iostream>
using namespace std;

#define MAX 500
int N, M;
int MAP[MAX][MAX] = { 0, };
int visit[MAX][MAX] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int ans = 0;

void Input()
{
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> MAP[r][c];
		}
	}
}

void T_type_chart(int x, int y)
{
	if (x + 2 < N && y + 1 < M) // た
	{
		ans = max(ans, MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y + 1]);
	}

	if (x + 2 < N && y - 1 >= 0) // っ
	{
		ans = max(ans, MAP[x][y] + MAP[x + 1][y] + MAP[x + 1][y - 1] + MAP[x + 2][y]);
	}

	if (x + 1 < N && y + 2 < M) // ぬ
	{
		ans = max(ans, MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x + 1][y + 1]);
	}

	if (x - 1 >= 0 && y + 2 < M) // で
	{
		ans = max(ans, MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x - 1][y + 1]);
	}
}

void dfs(int x, int y, int depth, int sum)
{
	if (depth == 3)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
		{
			continue;
		}
		if (visit[nx][ny] == 1)
		{
			continue;
		}

		visit[nx][ny] = 1;
		dfs(nx, ny, depth + 1, sum + MAP[nx][ny]);
		visit[nx][ny] = 0;
	}
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			T_type_chart(i, j);

			visit[i][j] = 1;
			dfs(i, j, 0, MAP[i][j]);
			visit[i][j] = 0;
		}
	}
}

int main(void)
{
	Input();
	solve();

	cout << ans << endl;
	return 0;
}