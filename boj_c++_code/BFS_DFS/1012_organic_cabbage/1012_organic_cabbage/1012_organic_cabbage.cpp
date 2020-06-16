#include <iostream>
#include <vector>
using namespace std;

int T;
int M, N, K;
int a, b;
int Map[50][50];
bool visit[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int next_x, next_y;
vector<int> ans_v;

void init() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
			Map[i][j] = 0;
		}
	}
}

void DFS(int y, int x) {
	Map[y][x] = -1;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];

		if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0 )
		{
			continue;
		}

		if ((Map[next_y][next_x] == 1) && (visit[next_y][next_x] == false))
		{
			DFS(next_y, next_x);
		}
	}
}

int Processing() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)
			{
				cnt++;
				DFS(i, j);
			}
		}
	}

	return cnt;
}

int main(void) {
	
	int ans;
	cin >> T;
	for (int k = 0; k < T; k++)
	{

		cin >> M >> N >> K;
		init();
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b;
			Map[b][a] = 1;
		}

		ans = Processing();
		ans_v.push_back(ans);
	}

	for (auto n : ans_v)
	{
		cout << n << endl;
	}

	return 0;
}