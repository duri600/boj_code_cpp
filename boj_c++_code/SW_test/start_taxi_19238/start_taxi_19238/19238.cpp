#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct taxi_state
{
	int r, c, g;
};

typedef pair<int, int> pos;
map<pos, pos> customer_list;


int ans;
int N, M, G;
int board[20][20];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void find_customer(taxi_state ts)
{
	queue<taxi_state> q;
	q.push(ts);
	while (!q.empty())
	{
		int start_r = q.front().r;
		int start_c = q.front().c;
		int start_g = q.front().g;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_r = start_r + dr[i];
			int next_c = start_c + dc[i];
			int next_g = start_g - 1;

			if (next_g < 0)
			{
				ans = -1;
				return;
			}

			if (next_r >= N || next_c >= N || next_r < 0 || next_c < 0)
			{
				continue;
			}

			if (board[next_r][next_c] == 401)
			{
				continue;
			}

			if (board[next_r][next_c] == 0)
			{
				taxi_state temp;
				temp.r = next_r;
				temp.c = next_c;
				temp.g = next_g;
				q.push(temp);
				continue;
			}

			if (board[next_r][next_c] != 0 && board[next_r][next_c] != 401)
			{
				int index = board[next_r][next_c];
				int dst_r = customer_list[{next_r, next_c}].first;
				int dst_c = customer_list[{next_r, next_c}].second;
			}

		}
	}



}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> G;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				board[r][c] = 401;
			}
			else
			{
				board[r][c] = 0;
			}
				
		}
	}
	taxi_state ts;
	cin >> ts.r >> ts.c;
	ts.g = G;

	for (int i = 1; i <= M; i++)
	{
		pos start;
		pos dst;
		cin >> start.first >> start.second >> dst.first >> dst.second;
		customer_list[start] = dst;
		board[start.first][start.second] = i;
	}

	find_customer(ts);

	return 0;
}