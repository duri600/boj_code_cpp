#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int N, M;
int temp;
int Map[1001][1001];
int visit[1001][1001][2];

typedef pair<int, int> P;
typedef pair<P, int> status;
queue<status> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cin >> temp;
			//scanf("%1d", &Map[i][j]);
			scanf("%1d", &temp);
			Map[i][j] = temp;
		}
	}
}


int BFS(status s) {
	q.push(s);
	visit[s.first.first][s.first.second][s.second] = 1;

	while (!q.empty())
	{
		int x = q.front().first.second;
		int y = q.front().first.first;
		int block = q.front().second;
		q.pop();

		if (y == (N-1) && x == (M-1)) {
			return visit[y][x][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0) {
				continue;
			}

			if ((Map[next_y][next_x] == 1) && block) {
				visit[next_y][next_x][block - 1] = visit[y][x][block] + 1;
				q.push({ { next_y,next_x }, block - 1 });
			}

			if ((Map[next_y][next_x] == 0) && (visit[next_y][next_x][block] == 0))
			{
				visit[next_y][next_x][block] = visit[y][x][block] + 1;
				q.push({ {next_y,next_x}, block });
			}


		}
	}
	return -1;

}


int main(void) {
	int ans;
	InputData();
	P start = { 0,0 };
	status s = { start,1 };
	ans = BFS(s);

	cout << ans;
	return 0;
}