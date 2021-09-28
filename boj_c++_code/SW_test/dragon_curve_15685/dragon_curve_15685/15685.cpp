#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N;
int x, y, d, g;
queue<pair<pair<int, int>, pair<int, int>>> q;
int MAP[MAX][MAX] = { 0, };
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };
vector<int> dir_q;

void dragon_curve()
{
	int size_q = dir_q.size();
	for (int i = size_q - 1; i >= 0; i--)
	{
		int ndir = (dir_q[i] + 1) % 4;
		x = x + dc[ndir];
		y = y + dr[ndir];
		MAP[x][y] = 1;
		dir_q.push_back(ndir);
	}
}

void count_square()
{
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (MAP[i][j] == 1 && MAP[i][j + 1] == 1
				&& MAP[i + 1][j] == 1 && MAP[i + 1][j + 1] == 1)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}

void solve()
{
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		d = q.front().second.first;
		g = q.front().second.second;
		q.pop();
		dir_q.clear();

		MAP[x][y] = 1;
		x = x + dc[d];
		y = y + dr[d];
		MAP[x][y] = 1;
		dir_q.push_back(d);

		for (int i = 0; i < g; i++)
		{
			dragon_curve();
		}
	}
	count_square();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		q.push({ {x,y},{d,g} });
	}

	solve();

	return 0;
}