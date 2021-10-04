#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int N, M, K;
int A[MAX][MAX] = { 0, };
int energy[MAX][MAX];
int visit[MAX][MAX] = { 0, };
//vector<pair<pair<int, int>, int>> tree_info;
map<pair<int,int>, vector<int>> tree_info; // (x,y), age
queue<pair<int, int>> tree_pos_spring;
queue<pair<int, int>> tree_pos_summer;
queue<pair<int, int>> tree_pos_autumn;
map<pair<int, int>, vector<int>> live_tree_info;
map<pair<int, int>, vector<int>> dead_tree_info;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void clear_queue(queue<pair<int,int>>& q)
{
	while (!q.empty())
	{
		q.pop();
	}
}

void spring(queue<pair<int, int>>& tree_pos_next)
{
	while (!tree_pos_spring.empty())
	{
		int x = tree_pos_spring.front().first;
		int y = tree_pos_spring.front().second;
		tree_pos_spring.pop();
		int flag = 0;
		int flag2 = 0;
		int flag3 = 0;

		vector<int> age_v = tree_info[{x, y}];
		sort(age_v.begin(), age_v.end());

		for (int i = 0; i < age_v.size(); i++)
		{
			int diff = energy[x][y] - age_v[i];
			if (diff >= 0)
			{
				energy[x][y] = diff;
				if ((age_v[i] + 1) % 5 == 0)
				{
					flag2 = 1;
				}
				live_tree_info[{x, y}].push_back((age_v[i] + 1));
				flag3 = 1;
				continue;
			}
			else
			{
				dead_tree_info[{x, y}].push_back(age_v[i]);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			tree_pos_summer.push({ x,y });
		}
		if (flag2 == 1)
		{
			tree_pos_autumn.push({ x,y });
		}
		if (flag3 == 1)
		{
			tree_pos_next.push({ x,y });
		}
	}

}

void summer()
{
	while(!tree_pos_summer.empty())
	{
		int x = tree_pos_summer.front().first;
		int y = tree_pos_summer.front().second;
		tree_pos_summer.pop();

		vector<int> d_tree = dead_tree_info[{x, y}];
		for (int i = 0; i < d_tree.size(); i++)
		{
			energy[x][y] = energy[x][y] + d_tree[i] / 2;
		}
	}
}

void autumn(queue<pair<int, int>>& tree_pos_next)
{
	while (!tree_pos_autumn.empty())
	{
		int x = tree_pos_autumn.front().first;
		int y = tree_pos_autumn.front().second;
		tree_pos_autumn.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == 0 || ny == 0 || nx > N || ny > N)
			{
				continue;
			}

			if (live_tree_info[{nx, ny}].empty())
			{
				tree_pos_next.push({ nx,ny });
			}
			live_tree_info[{nx, ny}].push_back(1);
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			energy[i][j] += A[i][j];
		}
	}
}

int solve()
{
	for (int year = 0; year < K; year++)
	{
		queue<pair<int, int>> tree_pos_next;
		//spring
		spring(tree_pos_next);

		//summer
		summer();

		//autumn
		autumn(tree_pos_next);

		//winter
		winter();

		tree_info = live_tree_info;
		live_tree_info.clear();
		tree_pos_spring = tree_pos_next;
	}

	int ans = 0;
	 //tree count
	while (!tree_pos_spring.empty())
	{
		int x = tree_pos_spring.front().first;
		int y = tree_pos_spring.front().second;
		tree_pos_spring.pop();
		ans += tree_info[{x, y}].size();
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			energy[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int mm = 0; mm < M; mm++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree_info[{x, y}].push_back(age);
		if (visit[x][y] == 0)
		{
			tree_pos_spring.push({ x,y });
			visit[x][y] = 1;
		}
	}

	int ret = solve();

	cout << ret;

	return 0;
}