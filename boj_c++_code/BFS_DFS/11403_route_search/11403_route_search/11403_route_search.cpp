#include <iostream>
#include <queue>
using namespace std;

int N;
int Map[100][100];
int tmp;
int ans_Map[100][100];
bool visit[100];
queue<int> q;
void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			Map[i][j] = tmp;
		}
	}
}

void Init_visit() {
	for (int i = 0; i < N; i++)
	{
		visit[i] = false;
	}
}

void solve_sy(int start) {

	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int j = 0; j < N; j++)
		{
			if ((Map[temp][j] == 1) && !visit[j])
			{
				q.push(j);
				visit[j] = true;
				ans_Map[start][j] = 1;
			}
		}
	}
}

void Processing() {
	for (int i = 0; i < N; i++)
	{
		Init_visit();
		solve_sy(i);
	}
}

void OutputData() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans_Map[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	InputData();

	Processing();

	OutputData();

	return 0;
}