#define MAX 100001
#include <iostream>
#include <queue>
using namespace std;

int N, K;
typedef pair<int, int> P;
queue<P> status;
int location;
int time;
bool visit[100010];

void InputData() {
	cin >> N >> K;
	status.push({N,0});
}

int BFS() {
	
	while (!status.empty())
	{
		location = status.front().first;
		time = status.front().second;
		status.pop();

		if (location == K)
		{
			return time;
		}
		
		if ((location + 1 < MAX) && (visit[location + 1]==false))
		{
			status.push({ location + 1, time + 1 });
			visit[location + 1] = true;
		}

		if ((location - 1 >= 0) && (visit[location - 1] == false))
		{
			status.push({ location - 1, time + 1 });
			visit[location - 1] = true;
		}

		if ((location * 2 < MAX) && (visit[location * 2] == false))
		{
			status.push({ location * 2, time + 1 });
			visit[location * 1] = true;
		}
	}


}

int main(void) {
	InputData();

	int ans = BFS();

	cout << ans;

	return 0;

}