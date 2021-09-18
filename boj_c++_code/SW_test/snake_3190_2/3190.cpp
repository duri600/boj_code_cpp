#include <iostream>
#include <queue>

#define MAX 101
using namespace std;
int MAP[MAX][MAX] = { 0, };
char dir_info[10001];
int N, K, L;
int dr[4] = { 0, 1, 0 ,-1 };
int dc[4] = { 1,0,-1,0 };
int snake[MAX][MAX] = { 0, };
queue<pair<int, int>> snake_tail;

void Input()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		MAP[r][c] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int time;
		char dir;
		cin >> time >> dir;
		dir_info[time] = dir;
	}
}

int solve()
{
	int r = 1;
	int c = 1;
	snake[r][c] = 1;
	snake_tail.push({ r,c });
	int dir = 0;
	int next_r = r;
	int next_c = c;
	int cnt = 0;
	while (1)
	{
		cnt++;
		next_r = next_r + dr[dir];
		next_c = next_c + dc[dir];
		if (next_r > N || next_c > N || next_r <= 0 || next_c <= 0)
		{
			break;
		}
		if (snake[next_r][next_c] == 1)
		{
			break;
		}

		snake[next_r][next_c] = 1;
		snake_tail.push({ next_r, next_c });
		if (MAP[next_r][next_c] == 1)
		{
			MAP[next_r][next_c] = 0;
		}
		else
		{
			int row = snake_tail.front().first;
			int col = snake_tail.front().second;
			snake_tail.pop();
			snake[row][col] = 0;
		}

		if (dir_info[cnt] == 'D')
		{
			dir = dir + 1;
			if (dir == 4)
			{
				dir = 0;
			}
		}
		else if (dir_info[cnt] == 'L')
		{
			dir = dir - 1;
			if (dir == -1)
			{
				dir = 3;
			}
		}
	}

	return cnt;
}

int main(void)
{

	Input();
	int ans = solve();
	cout << ans << endl;
	return 0;
}