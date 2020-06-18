#include <iostream>
using namespace std;

char color_Map[100][100];
int int_Map_a[100][100];
int int_Map_b[100][100];
int N;
bool visit_a[100][100];
bool visit_b[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int count_a = 0;
int count_b = 0;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> color_Map[i][j];
		}
	}
}

void Init() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit_a[i][j] = false;
			visit_b[i][j] = false;
		}
	}
}

void Mapping() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (color_Map[i][j])
			{

			case 'R':
				int_Map_a[i][j] = 1;
				int_Map_b[i][j] = 1;
				break;

			case 'G':
				int_Map_a[i][j] = 2;
				int_Map_b[i][j] = 1;
				break;
			case 'B':
				int_Map_a[i][j] = 3;
				int_Map_b[i][j] = 3;
				break;
			default:
				break;
			}
		}
	}
}

void DFS_a(int y, int x) {
	int color_ind = int_Map_a[y][x];
	visit_a[y][x] = true;
	int_Map_a[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0) {
			continue;
		}

		if (!visit_a[next_y][next_x] && (int_Map_a[next_y][next_x] == color_ind))
		{
			DFS_a(next_y, next_x);
		}
	}
}

void DFS_b(int y, int x) {
	int color_ind = int_Map_b[y][x];
	visit_b[y][x] = true;
	int_Map_b[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0) {
			continue;
		}

		if (!visit_b[next_y][next_x] && (int_Map_b[next_y][next_x] == color_ind))
		{
			DFS_b(next_y, next_x);
		}
	}
}

void Processing() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (int_Map_a[i][j] != 0)
			{
				DFS_a(i, j);
				count_a++;
			}
			if (int_Map_b[i][j] != 0)
			{
				DFS_b(i, j);
				count_b++;
			}
		}
	}
}

int main(void) {
	InputData();

	Mapping();

	Init();
	Processing();

	cout << count_a << " " << count_b << endl;

	return 0;
}
