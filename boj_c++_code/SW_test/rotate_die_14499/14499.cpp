#include <iostream>
#include <queue>
#include <vector>
#define MAX 21
using namespace std;

int Map[MAX][MAX] = { 0, };
int N, M;
int x, y;
int K;
int die[7] = { 0, };
queue<int> dir_q;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
vector<int> ans_v;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void rotate_die(int dir)
{
	if (dir == 1)
	{
		int temp;
		temp = die[1];
		die[1] = die[4];
		die[4] = die[6];
		die[6] = die[3];
		die[3] = temp;
	}
	else if (dir == 2)
	{
		int temp;
		temp = die[1];
		die[1] = die[3];
		die[3] = die[6];
		die[6] = die[4];
		die[4] = temp;
	}
	else if (dir == 3)
	{
		int temp;
		temp = die[1];
		die[1] = die[5];
		die[5] = die[6];
		die[6] = die[2];
		die[2] = temp;
	}
	else if (dir == 4)
	{
		int temp;
		temp = die[1];
		die[1] = die[2];
		die[2] = die[6];
		die[6] = die[5];
		die[5] = temp;
	}
}


void solve()
{
	ans_v.clear();
	int next_x = x;
	int next_y = y;
	int die_bottom = 6;
	//ans_v.push_back(0);
	while (!dir_q.empty())
	{
		int dir = dir_q.front();
		dir_q.pop();
		next_x = next_x + dx[dir];
		next_y = next_y + dy[dir];
		if (next_x >= N || next_y >= M || next_x < 0 || next_y < 0)
		{
			next_x = next_x - dx[dir];
			next_y = next_y - dy[dir];
			continue;
		}
		rotate_die(dir);
		if (Map[next_x][next_y] == 0)
		{
			Map[next_x][next_y] = die[die_bottom];
		}
		else
		{
			die[die_bottom] = Map[next_x][next_y];
			Map[next_x][next_y] = 0;
		}
		
		ans_v.push_back(die[1]);
	}
	
}

int main(void)
{
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int k = 0; k < K; k++)
	{
		int temp;
		cin >> temp;
		dir_q.push(temp);
	}
	solve();

	for (int i = 0; i < ans_v.size(); i++)
	{
		cout << ans_v[i] << endl;
	}
	return 0;
}