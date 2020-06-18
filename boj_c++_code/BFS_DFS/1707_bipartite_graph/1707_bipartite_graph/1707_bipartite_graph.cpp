#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int K;
int V, E;
int a, b;
bool visit[20000];
queue<int> q_a;
queue<int> q_b;
map<int, vector<int>> m;


int check(queue<int> qu) {
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		for (int i = 0; i < V; i++)
		{
			if (find(m[temp].begin(),m[temp].end(),i) != m[temp].end())
			{
				return 0;
			}
		}
	}
	return 1;
}

void permutation(int depth) {
	if (depth == V)
	{
		while (!q_a.empty()) q_a.pop();
		while (!q_b.empty()) q_b.pop();
		for (int k = 0; k < V; k++)
		{
			if (visit[k] == 1)
			{
				q_a.push(k);
			}
			else
			{
				q_b.push(k);
			}
		}
		return;
	}
	else if (depth == 0)
	{
		visit[0] = 1;
		permutation(depth + 1);
	}
	else
	{
		visit[depth] = 1;
		permutation(depth + 1);
		visit[depth] = 0;
		permutation(depth + 1);

	}
}

int main(void) {
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			cin >> a >> b;
			m[a].push_back(b);
			m[b].push_back(a);
		}

		permutation(0);

		if (check(q_a) && check(q_b))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}