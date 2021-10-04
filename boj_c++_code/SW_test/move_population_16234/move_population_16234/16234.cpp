#include <iostream>
#include <queue>
#include <vector>
#define MAX 51
using namespace std;

int N, L, R;

int A[MAX][MAX] = { 0, };

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> pos_q;
int ans = 0;

void make_group(int r, int c, int visit[][MAX], vector<int> &sum_v, vector<int>& mem_v, int g, bool &check_g)
{
	int sum = 0;
	int member = 0;
	int avg = 0;
	visit[r][c] = g;
	pos_q.push({ r,c });
	while (!pos_q.empty())
	{
		int cr = pos_q.front().first;
		int cc = pos_q.front().second;
		pos_q.pop();
		sum = sum + A[cr][cc];
		member++;
		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
		
			if (nr >= N || nc >= N || nr < 0 || nc < 0)
			{
				continue;
			}
			if (visit[nr][nc] != 0)
			{
				continue;
			}
			int diff = abs(A[cr][cc] - A[nr][nc]);
			if (diff >= L && diff <= R)
			{
				visit[nr][nc] = g;
				pos_q.push({ nr,nc });
			}

		}
	}
	if (check_g == false)
	{
		if (member != 1)
		{
			check_g = true;
		}
	}

	sum_v.push_back(sum);
	mem_v.push_back(member);
}

void solve()
{
	bool move_check = true;
	while (move_check)
	{
		int group = 1;
		int visit[MAX][MAX] = { 0, };
		vector<int> sum;
		vector<int> member;
		move_check = false;
		vector<int> g_v;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0)
				{
					make_group(i, j, visit, sum, member, group, move_check);
					group++;
				}

			}
		}

		if (move_check == false)
		{
			return;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int group_v = visit[i][j] - 1;
				A[i][j] = sum[group_v] / member[group_v];
			}
		}
		ans++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	solve();

	cout << ans;
	return 0;
}