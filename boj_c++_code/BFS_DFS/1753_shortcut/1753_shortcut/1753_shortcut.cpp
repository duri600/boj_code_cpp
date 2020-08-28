#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int V, E;
int first;
int start, fin, weight;
//int map[20010][20010];
queue<int> q;
typedef pair<int, int> P;
map<int, vector<P>> graph;
int visit[20010];
int dist[20010];

void bfs(int st_point)
{
	q.push(st_point);
	visit[st_point] = 1;
	dist[st_point] = 0;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		P tmp = graph[temp].front();

	}

}

int main(void)
{
	cin >> V >> E;
	cin >> first;

	for (int i = 0; i < E; i++)
	{
		cin >> start >> fin >> weight;
		graph[start].push_back({ fin,weight });
	}

	bfs(first);
}