#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a, b;
int next_x;
int next_y;
int Map[1010][1010];
bool visit[1010];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int connect_num = 0;
int q_size = 0;
queue<int> q;

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Map[a][b] = 1;
		Map[b][a] = 1;
	}
	for (int j = 1; j <= N; j++)
	{
		visit[j] = false;
	}
}

int Processing() {

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			q.push(i);
			visit[i] = true;
			q_size++;
			while (!q.empty())
			{
				int temp = q.front();
				for (int j = 1; j <= N; j++)
				{
					if ((Map[temp][j] == 1) && !visit[j])
					{
						q.push(j);
						visit[j] = true;
						q_size++;
					}
				}
				q.pop();
				q_size--;
				if (q_size == 0)
				{
					connect_num++;
				}
			}
		}
	}
	return connect_num;
}

int main(void) {
	int ans;
	InputData();

	ans = Processing();

	cout << ans;

	return 0;
}