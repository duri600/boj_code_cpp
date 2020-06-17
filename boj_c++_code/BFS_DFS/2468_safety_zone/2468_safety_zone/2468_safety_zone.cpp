#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Map[100][100];
int Map_b[100][100];
bool visit[100][100];
int temp;
vector<int> height;
vector<int> answer;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			Map[i][j] = temp;
			height.push_back(temp);
		}
	}
}

void Binary(int h) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] > h)
			{
				Map_b[i][j] = 1;
			}
			else
			{
				Map_b[i][j] = 0;
			}
		}
	}
}

void BFS(int y, int x) {
	int next_x, next_y;
	Map_b[y][x] = -1;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];

		if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0) {
			continue;
		}

		if ((Map_b[next_y][next_x] == 1) && !visit[next_y][next_x])
		{
			BFS(next_y, next_x);
		}
	}
}

void init_visit() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
	}
}

int Find_safezone() {
	int zone = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map_b[i][j] == 1)
			{
				BFS(i, j);
				zone++;
				init_visit();
			}
		}
	}
	return zone;
}

void Processing() {
	sort(height.begin(), height.end());
	height.erase(unique(height.begin(), height.end()), height.end());
	if (height.size() == 1)
	{
		answer.push_back(1);
	}
	else
	{
		int zone = 0;
		for (auto n : height)
		{
			Binary(n);
			zone = Find_safezone();
			answer.push_back(zone);
		}
	}
}

bool comp(int a, int b) {
	return a > b;
}

void Output() {
	sort(answer.begin(), answer.end(), comp);
	cout << answer.front();
}

int main(void) {
	InputData();

	Processing();

	Output();

	return 0;
}