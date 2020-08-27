#include <iostream>
#include <queue>
using namespace std;

int w, h;
int map[50][50];
int visit[50][50];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
typedef pair<int, int> P;
queue<P> q;

void Init()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

void bfs(int y, int x)
{
	visit[y][x] = 1;
	q.push({ y,x });
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int next_y = temp.first + dy[i];
			int next_x = temp.second + dx[i];

			if (next_y >= h || next_x >= w || next_y < 0 || next_x < 0)
			{
				continue;
			}

			if (map[next_y][next_x] == 1 && visit[next_y][next_x] == 0)
			{
				visit[next_y][next_x] = 1;
				q.push({ next_y,next_x });
			}
		}
	}
}

int find_island()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == 0)
			{
				visit[i][j] = 1;
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void)
{	
	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		Init();
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int ans = find_island();

		cout << ans << endl;
	}

	return 0;
}