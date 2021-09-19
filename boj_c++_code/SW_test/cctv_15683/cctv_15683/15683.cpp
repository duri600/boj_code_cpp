#include <iostream>
#include <queue>
#define MAX 8
using namespace std;

int N;
int M;
int MAP[MAX][MAX] = { 0, };
vector<pair<int, pair<int, int>>> info_v;
int ans = 100;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void fill_i(int sr, int sc, int dir)
{
	if (dir > 3)
	{
		dir = dir - 4;
	}
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	while (!q.empty())
	{
		int nr = q.front().first + dr[dir];
		int nc = q.front().second + dc[dir];
		q.pop();
		if (MAP[nr][nc] == 6 || nr >= N || nc >= M || nr < 0 || nc < 0)
		{
			continue;
		}
		MAP[nr][nc]++;
		q.push({ nr,nc });
	}
}

void delete_i(int sr, int sc, int dir)
{
	if (dir > 3)
	{
		dir = dir - 4;
	}
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	while (!q.empty())
	{
		int nr = q.front().first + dr[dir];
		int nc = q.front().second + dc[dir];
		q.pop();
		if (MAP[nr][nc] == 6 || nr >= N || nc >= M || nr < 0 || nc < 0)
		{
			continue;
		}
		MAP[nr][nc]--;
		q.push({ nr,nc });
	}
}

void dfs(int len)
{
	if (len == info_v.size())
	{
		int zero_cnt = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (MAP[r][c] == 9)
				{
					zero_cnt++;
				}
			}
		}
		ans = min(ans, zero_cnt);
		return;
	}
	int dir_case;
	int cctv_n = info_v[len].first;
	int cctv_r = info_v[len].second.first;
	int cctv_c = info_v[len].second.second;

	if (cctv_n == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			// i 방향으로 채우기
			fill_i(cctv_r, cctv_c, i);
			dfs(len + 1);
			// i 방향으로 지우기
			delete_i(cctv_r, cctv_c, i);
		}
	}
	else if (cctv_n == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			// i 방향으로 채우기
			fill_i(cctv_r, cctv_c, i);
			fill_i(cctv_r, cctv_c, i + 2);
			dfs(len + 1);
			// i 방향으로 지우기
			delete_i(cctv_r, cctv_c, i);
			delete_i(cctv_r, cctv_c, i + 2);
		}
	}
	else if (cctv_n == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			// i 방향으로 채우기
			fill_i(cctv_r, cctv_c, i);
			fill_i(cctv_r, cctv_c, i + 1);
			dfs(len + 1);
			// i 방향으로 지우기
			delete_i(cctv_r, cctv_c, i);
			delete_i(cctv_r, cctv_c, i + 1);
		}
	}
	else if (cctv_n == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			// i 방향으로 채우기
			fill_i(cctv_r, cctv_c, i);
			fill_i(cctv_r, cctv_c, i + 1);
			fill_i(cctv_r, cctv_c, i + 2);
			dfs(len + 1);
			// i 방향으로 지우기
			delete_i(cctv_r, cctv_c, i);
			delete_i(cctv_r, cctv_c, i + 1);
			delete_i(cctv_r, cctv_c, i + 2);
		}
	}
	else if (cctv_n == 5)
	{
		fill_i(cctv_r, cctv_c, 0);
		fill_i(cctv_r, cctv_c, 1);
		fill_i(cctv_r, cctv_c, 2);
		fill_i(cctv_r, cctv_c, 3);
		dfs(len + 1);
		delete_i(cctv_r, cctv_c, 0);
		delete_i(cctv_r, cctv_c, 1);
		delete_i(cctv_r, cctv_c, 2);
		delete_i(cctv_r, cctv_c, 3);
	}	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> MAP[r][c];
			if (MAP[r][c] == 0)
			{
				MAP[r][c] = 9;
			}
			else if (MAP[r][c] != 6)
			{
				info_v.push_back({ MAP[r][c],{r,c} });
			}
		}
	}

	dfs(0);

	cout << ans;

	return 0;
}