#include <iostream>
#include <queue>
using namespace std;

int M, N;
int Box[1010][1010];
queue<pair<int,int>> box_index;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int step_q_size;
int next_size = 0;
int ans = 0;

void InputData() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Box[i][j];
			if (Box[i][j] == 1)
			{
				box_index.push({ i,j });
			}
		}
	}
}

void bfs(int y, int x) {
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_y >= N || next_y < 0 || next_x >= M || next_x < 0)
		{
			continue;
		}

		if (Box[next_y][next_x] == 0) {
			Box[next_y][next_x] = 1;
			next_size++;
			box_index.push({ next_y,next_x });
		}
	}
	return;
}

int Processing() {
	step_q_size = box_index.size();
	while (box_index.size())
	{
		pair<int, int> start = box_index.front();
		bfs(start.first, start.second);
		step_q_size--;
		if (step_q_size == 0) {
			step_q_size = next_size;
			next_size = 0;
			ans++;
		}
		box_index.pop();
	}
	ans--;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Box[i][j] == 0)
			{
				ans = -1;
			}
		}
	}

	return ans;
}



int main(void) {
	int time;

	InputData();

	time = Processing();

	cout << time;

	return 0;
}