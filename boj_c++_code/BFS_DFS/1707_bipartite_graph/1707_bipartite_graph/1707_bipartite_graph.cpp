#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int K;
int V, E;
int a, b;
bool visit[20001];
queue<int> q_a;
queue<int> q_b;
map<int, vector<int>> m;


int check(queue<int> qu) {
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		for (int i = 1; i <= V; i++)
		{
			if (find(m[temp].begin(),m[temp].end(),i) != m[temp].end())
			{
				return 0;
			}
		}
	}
	return 1;
}

void permutation(int size, int depth) {

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

		for (int aaa = 1; aaa <= V; aaa++)
		{
			permutation(aaa, 0);
		}
		
	}

	return 0;
}