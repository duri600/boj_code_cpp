#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[101];
int visit[101];
queue<int> q;
vector<int> ans;

void InputData() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		visit[i] = 0;
	}
}

void Insert(queue<int> &qqq) {
	while (!qqq.empty()) {
		int temp = qqq.front();
		ans.push_back(temp);
		qqq.pop();
	}
}

void Init(queue<int> &qq) {
	while (!qq.empty()) {
		int temp = qq.front();
		visit[temp] = 0;
		qq.pop();
	}
}

void dfs(int start) {
	visit[start] = 1;
	q.push(start);
	
	if (visit[arr[start]] == 1)
	{
		if (arr[start] == q.front())
		{
			Insert(q);
			return;
		}
		else
		{
			Init(q);
			return;
		}
	}
	else
	{
		visit[arr[start]] = 1;
		dfs(arr[start]);
	}
}

void Processing() {
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
		}
	}
}

int main(void) {
	InputData();

	Processing();
	int sz = ans.size();
	cout << sz << endl;
	sort(ans.begin(), ans.end());
	for (auto n : ans)
	{
		cout << n << endl;
	}

	return 0;
}