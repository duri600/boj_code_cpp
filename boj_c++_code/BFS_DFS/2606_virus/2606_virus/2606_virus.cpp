#include <iostream>
#include <queue>
using namespace std;

int Computer;
int Connect;
int map[101][101];
int visit[101];
queue<int> q;

void BFS(int start)
{
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= Computer; i++)
		{
			if (map[temp][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(void)
{
	cin >> Computer;
	cin >> Connect;

	for (int i = 0; i < Connect; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(1);
	int ans = 0;
	for (int i = 1; i <= Computer; i++)
	{
		ans += visit[i];
	}

	cout << ans - 1;

	return 0;
}