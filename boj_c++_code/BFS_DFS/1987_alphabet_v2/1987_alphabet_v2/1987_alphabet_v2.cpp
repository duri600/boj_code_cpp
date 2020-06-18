#include <iostream>
#include <queue>
using namespace std;

int R, C;
char Map[20][20];
int int_map[20][20];
bool visit[27];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 1;

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

void DFS(int y, int x, int cnt) {
	visit[int_map[y][x]] = true;
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) {
			continue;
		}

		if (!visit[int_map[next_y][next_x]])
		{
			visit[int_map[next_y][next_x]] = true;
			DFS(next_y, next_x, cnt + 1);
			visit[int_map[next_y][next_x]] = false;
		}
	}

}

int main(void) {
	InputData();

	Init();
	DFS(0, 0, 1);

	cout << ans << endl;

	return 0;
}