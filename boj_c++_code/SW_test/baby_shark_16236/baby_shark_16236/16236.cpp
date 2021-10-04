#include <iostream>
#include <queue>
using namespace std;

int N;
int space[20][20];
int visit[20][20];

struct SHARK
{
	int x, y, time;
};

SHARK shark;
int shark_size;
int shark_eat;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				shark.time = 0;
				shark_size = 2;
				shark_eat = 0;
				space[i][j] = 0;
			}
		}
	}

	bool next_step = true;
	while (next_step)
	{
		next_step = false;
		int visit[20][20] = { 0, };
		
		queue<SHARK> q;
		visit[shark.x][shark.y] = 1;
		q.push(shark);

		SHARK candi;
		candi.x = 20;
		candi.time = -1;

		while (!q.empty())
		{
			SHARK cur = q.front();
			q.pop();

			if (candi.time != -1 && candi.time < cur.time)
			{
				break;
			}

			if ((space[cur.x][cur.y] < shark_size) && (space[cur.x][cur.y] != 0))
			{
				next_step = true;
				if (candi.x > cur.x || (candi.x == cur.x && candi.y > cur.y))
				{
					candi = cur;
				}
			}

			for (int i = 0; i < 4; i++)
			{
				SHARK next;
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				next.time = cur.time + 1;

				if (next.x >= N || next.y >= N || next.x < 0 || next.y < 0)
				{
					continue;
				}

				if (visit[next.x][next.y] == 0 && space[next.x][next.y] <= shark_size)
				{
					q.push(next);
					visit[next.x][next.y] = 1;
				}
			}
		}

		if (next_step)
		{
			shark = candi;
			shark_eat++;
			if (shark_eat == shark_size)
			{
				shark_size++;
				shark_eat = 0;
			}
			space[shark.x][shark.y] = 0;
		}

	}

	cout << shark.time;


	return 0;
}