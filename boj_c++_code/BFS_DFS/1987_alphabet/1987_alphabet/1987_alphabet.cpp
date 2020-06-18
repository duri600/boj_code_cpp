#include <iostream>
#include <queue>
using namespace std;

int R, C;
char Map[20][20];
int int_map[20][20];
typedef pair<int, int> LOC;
typedef pair<LOC, int> Data;
bool visit[27];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int route_count = 0;
queue<LOC> q;

void Init() {
	for (int i = 0; i < 26; i++)
	{
		visit[i] = false;
	}
}

void InputData() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
			int_map[i][j] = (int)Map[i][j] - 65;
		}
	}
}

void BFS(int y, int x) {
	q.push({ y, x });
	route_count++;
	while (!q.empty())
	{
		int cur_x = q.front().second;
		int cur_y = q.front().first;
		q.pop();
		visit[int_map[cur_y][cur_x]] = true;

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) {
				continue;
			}

			if (!visit[int_map[next_y][next_x]])
			{
				visit[int_map[next_y][next_x]] = true;
				q.push({ next_y,next_x });
				route_count++;
			}
		}
	}
}

int main(void) {
	InputData();

	Init();
	BFS(0, 0);

	cout << route_count << endl;

	return 0;
}