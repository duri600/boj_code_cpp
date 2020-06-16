#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int connect[1010][1010];
bool visit_b[1010];
bool visit_d[1010];
queue<int> bfs_q;

void InputData() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		connect[a][b] = 1;
		connect[b][a] = 1;
	}
}

void DFS(int start) {

	cout << start << " ";

	for (int i = 1; i <= N; i++)
	{
		if (connect[start][i] && !visit_d[i])
		{
			visit_d[i] = true;
			DFS(i);
		}
	}
}

void BFS(int start) {
	bfs_q.push(start);
	visit_b[start] = 1;

	while (!bfs_q.empty()) {
		start = bfs_q.front();
		bfs_q.pop();
		cout << start << " ";

		for (int i = 1; i <= N; i++)
		{
			if (connect[start][i] && !visit_b[i])
			{
				visit_b[i] = true;
				bfs_q.push(i);
			}
		}
	}
}

int main(void) {
	InputData();

	visit_b[V] = 1;
	visit_d[V] = 1;

	DFS(V);

	cout << endl;

	BFS(V);

	return 0;
}