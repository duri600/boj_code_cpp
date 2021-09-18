#include <iostream>
#include <queue>
#include <string>

#define MAX 101
using namespace std;

int apple[MAX][MAX] = { 0, };
char dir_list[10001];
queue<pair<int, int>> snake;
int snake_map[MAX][MAX] = { 0, };

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int solve(int N)
{
	int time = 0;
	snake.push({ 0,0 });
	snake_map[0][0] = 1;

	int direction = 0;
	int next_x = 0;
	int next_y = 0;

	while (1)
	{
		time++;
		next_x = next_x + dx[direction];
		next_y = next_y + dy[direction];

		if (next_x >= N || next_y >= N || next_x < 0 || next_y < 0)
		{
			break;
		}

		if (snake_map[next_x][next_y] == 1)
		{
			break;
		}

		snake_map[next_x][next_y] = 1;
		snake.push({ next_x, next_y });

		if (apple[next_x][next_y] == 1)
		{	
			apple[next_x][next_y] = 0;
		}
		else
		{
			int del_x = snake.front().first;
			int del_y = snake.front().second;
			snake.pop();
			snake_map[del_x][del_y] = 0;
		}

		if (dir_list[time] == 'D')
		{
			direction = direction + 1;
			if (direction == 4)
			{
				direction = 0;
			}
		}

		if (dir_list[time] == 'L')
		{
			direction = direction - 1;
			if (direction == -1)
			{
				direction = 3;
			}
		}
	}

	return time;

}

int main(void)
{
	int N;
	cin >> N;

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int app_x, app_y;
		cin >> app_x >> app_y;
		apple[app_y - 1][app_x - 1] = 1;
	}

	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int time = 0;
		char dir;
		cin >> time >> dir;
		dir_list[time] = dir;
	}

	int ans = solve(N);

	cout << ans << endl;

	return 0;
}