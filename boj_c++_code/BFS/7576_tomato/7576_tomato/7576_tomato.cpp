#include <iostream>
#include <queue>
using namespace std;

int M, N;
int Box[1010][1010];
queue<int> box_index;

void InputData() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Box[j][i];
		}
	}
}

void findTomato() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Box[j][i] == 1)
			{
				box_index.push(j);
			}
		}
	}
}

int main(void) {
	InputData();

	return 0;
}