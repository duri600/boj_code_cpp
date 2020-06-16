#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int new_x, new_y;
int N;
int Map[25][25];
bool visit[25][25];
int viliage;
int house = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> house_cnt;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cin >> Map[i][j];
			scanf("%1d", &Map[i][j]);
		}
	}
}

void DFS(int y, int x) {

	house++;
	Map[y][x] = -1;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];

		if (new_x >= N || new_y >= N || new_x < 0 || new_y < 0) {
			continue;
		}
		if ((visit[new_y][new_x] == false) && (Map[new_y][new_x] == 1))
		{
			DFS(new_y, new_x);
		}
		

	}
}

int Processing() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((Map[i][j] == 1) && (visit[i][j] == false))
			{
				viliage++;
				DFS(i, j);
				house_cnt.push_back(house);
				house = 0;
			}
		}
	}
	return viliage;
}

int main(void) {
	int total;
	InputData();

	total = Processing();

	cout << total << endl;
	sort(house_cnt.begin(), house_cnt.end());
	for (auto n : house_cnt) {
		cout << n << endl;
	}

	return 0;
}