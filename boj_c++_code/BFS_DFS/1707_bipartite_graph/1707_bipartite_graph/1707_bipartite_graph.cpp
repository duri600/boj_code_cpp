#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define RED 1
#define BLUE 2

int K, V, E;
map<int, vector<int>> graph;
int visit[20001];

void bfs(int start)
{
	queue<int> q;
	int color = RED;

	visit[start] = color;
	q.push(start);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		if (visit[front] == RED)
		{
			color = BLUE;
		}
		else if (visit[front] == BLUE)
		{
			color = RED;
		}

		int map_size = graph[front].size();
		for (int i = 0; i < map_size; i++)
		{
			int next = graph[front][i];
			if (!visit[next])
			{
				visit[next] = color;
				q.push(next);
			}
		}
	}
}

bool check_graph()
{
	for (int i = 1; i <= V; i++)
	{
		int graph_size = graph[i].size();
		for (int j = 0; j < graph_size; j++)
		{
			int next = graph[i][j];
			if (visit[i] == visit[next])
			{
				return false;
			}
		}
	}
	return true;
}

void Initialize()
{
	for (int i = 0; i <= V; i++)
	{
		graph[i].clear();
		visit[i] = 0;
	}
}

int main(void)
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int k = 1; k <= V; k++)
		{
			if (!visit[k])
			{
				bfs(k);
			}
		}

		if (check_graph())
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		Initialize();

	}
}