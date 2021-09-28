#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int N, M;
int MAP[MAX][MAX] = { 0, };
vector<pair<int, int>> h_v;
vector<pair<int, int>> c_v;
vector<pair<int, int>> exist_c;
int visit[13] = { 0, };
int ans = 987654321;
int calc_dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int ind, int len)
{
	if (len == M)
	{
		int temp = 0;
		for (int h = 0; h < h_v.size(); h++)
		{
			int dist = 987654321;
			for (int c = 0; c < exist_c.size(); c++)
			{
				dist = min(dist, calc_dist(h_v[h], exist_c[c]));
			}
			temp += dist;
		}
		ans = min(ans, temp);
		return;
	}

	for (int i = ind; i < c_v.size(); i++)
	{
		if (visit[i] == 1)
		{
			continue;
		}
		visit[i] = 1;
		exist_c.push_back(c_v[i]);
		solve(i, len + 1);
		visit[i] = 0;
		exist_c.pop_back();
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
		for (int c = 0; c < N; c++)
		{
			cin >> MAP[r][c];
			if (MAP[r][c] == 1)
			{
				h_v.push_back({ r,c });
			}
			if (MAP[r][c] == 2)
			{
				c_v.push_back({ r,c });
			}
		}
	}

	solve(0, 0);
	cout << ans;

	return 0;
}