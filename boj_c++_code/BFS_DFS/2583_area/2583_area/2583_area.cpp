#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
int Map[100][100];
int temp;
int X1, Y1;
int X2, Y2;
typedef pair<int, int> P;
queue<P> loc;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool visit[100][100];
queue<P> point;
int count_sy = 1;
vector<int> ans;

void InputData() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		loc.push({ X1,Y1 });
		loc.push({ X2,Y2 });
	}
}

void Coloring_Map() {
	while (!loc.empty())
	{
		int start_x = loc.front().second;
		int start_y = loc.front().first;
		loc.pop();
		int end_x = loc.front().second;
		int end_y = loc.front().first;
		loc.pop();

		for (int i = start_y; i < end_y; i++)
		{
			for (int j = start_x; j < end_x; j++)
			{
				Map[i][j]++;
			}
		}
	}
}

void BFS(int y, int x) {
	point.push({ y,x });	
	while (!point.empty())
	{
		int cur_x = point.front().second;
		int cur_y = point.front().first;
		visit[cur_y][cur_x] = true;
		Map[cur_y][cur_x] = -1;
		point.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0) {
				continue;
			}

			if ((Map[next_y][next_x] == 0) && !visit[next_y][next_x]) 
			{
				visit[next_y][next_x] = true;
				point.push({ next_y,next_x });
				count_sy++;
			}

		}
	}
}

int Processing() {
	int area_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 0)
			{
				BFS(i, j);
				area_cnt++;
				ans.push_back(count_sy);
				count_sy = 1;
			}
		}
	}

	return area_cnt;
}

void OutputData() {

}

int main(void) {
	int total_area;
	InputData();

	Coloring_Map();

	total_area = Processing();

	cout << total_area << endl;

	sort(ans.begin(), ans.end());

	for (auto n : ans)
	{
		cout << n << " ";
	}

	return 0;
}