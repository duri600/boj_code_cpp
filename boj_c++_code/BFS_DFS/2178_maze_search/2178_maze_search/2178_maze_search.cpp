#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
bool visit[101][101];
int bfs_size;
int next_q_size;
typedef pair<int, int> P;
queue<P> map_q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int next_x, next_y;
int ans;

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
			visit[i][j] = false;
		}
	}
}

int BFS(P start) {
	map_q.push(start);
	bfs_size = map_q.size();
	visit[start.second][start.first] = true;

	while (map_q.size()) {
		P index = map_q.front();
		if ((index.second == (M-1)) && (index.first == (N-1)))
		{
			ans++;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			next_x = index.second + dx[i];
			next_y = index.first + dy[i];

			if ( next_x >= M || next_x < 0 || next_y >=N || next_y < 0)
			{
				continue;
			}

			if ((map[next_y][next_x] == 1) && (visit[next_y][next_x] == 0)) {
				visit[next_y][next_x] = true;
				next_q_size++;
				map_q.push({ next_y,next_x });
			}
		}

		bfs_size--;
		if (bfs_size == 0)
		{
			bfs_size = next_q_size;
			next_q_size = 0;
			ans++;
		}
		map_q.pop();
	}

	return ans;
}

int main(void) {
	int result;

	InputData();
	P start = { 0,0 };
	result = BFS(start);

	cout << result;
	return 0;
}