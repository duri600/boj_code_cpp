#include <iostream>
#include <queue>
#define MAX 8
using namespace std;

// 2 -> right , 6 -> left
int left_ind = 6;
int right_ind = 2;
int saw_info[5][MAX + 1] = { 0, };
int K;
queue<pair<int, int>> q;

void spin(int saw_ind, int dir)
{
	if (dir == 1)
	{
		int temp;
		temp = saw_info[saw_ind][7];
		saw_info[saw_ind][7] = saw_info[saw_ind][6];
		saw_info[saw_ind][6] = saw_info[saw_ind][5];
		saw_info[saw_ind][5] = saw_info[saw_ind][4];
		saw_info[saw_ind][4] = saw_info[saw_ind][3];
		saw_info[saw_ind][3] = saw_info[saw_ind][2];
		saw_info[saw_ind][2] = saw_info[saw_ind][1];
		saw_info[saw_ind][1] = saw_info[saw_ind][0];
		saw_info[saw_ind][0] = temp;
	}
	else
	{
		int temp;
		temp = saw_info[saw_ind][0];
		saw_info[saw_ind][0] = saw_info[saw_ind][1];
		saw_info[saw_ind][1] = saw_info[saw_ind][2];
		saw_info[saw_ind][2] = saw_info[saw_ind][3];
		saw_info[saw_ind][3] = saw_info[saw_ind][4];
		saw_info[saw_ind][4] = saw_info[saw_ind][5];
		saw_info[saw_ind][5] = saw_info[saw_ind][6];
		saw_info[saw_ind][6] = saw_info[saw_ind][7];
		saw_info[saw_ind][7] = temp;
	}

}

void solve()
{
	while (!q.empty())
	{
		int saw_ind = q.front().first;
		int rotate = q.front().second;
		q.pop();

		int state1 = saw_info[saw_ind][left_ind];
		int state2 = saw_info[saw_ind][right_ind];
		spin(saw_ind, rotate);

		int left_side = saw_ind - 1;
		int state_l = state1;
		int rotate_l = rotate;
		while (left_side >= 1)
		{
			int state_2 = saw_info[left_side][right_ind];
			if (state_l != state_2)
			{
				state_l = saw_info[left_side][left_ind];
				spin(left_side, -rotate_l);
				left_side--;
				rotate_l = -rotate_l;
			}
			else
			{
				break;
			}
		}

		int right_side = saw_ind + 1;
		int state_r = state2;
		int rotate_r = rotate;
		while (right_side <= 4)
		{
			int state_2 = saw_info[right_side][left_ind];
			if (state_r != state_2)
			{
				state_r = saw_info[right_side][right_ind];
				spin(right_side, -rotate_r);
				right_side++;
				rotate_r = -rotate_r;
			}
			else
			{
				break;
			}
		}
	}
	
}

int main(void)
{

	for (int i = 1; i <= 4; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			saw_info[i][j] = temp[j] - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push({ a,b });
	}

	solve();
	int ans = 0;

	if (saw_info[1][0] == 1)
	{
		ans += 1;
	}
	if (saw_info[2][0] == 1)
	{
		ans += 2;
	}
	if (saw_info[3][0] == 1)
	{
		ans += 4;
	}
	if (saw_info[4][0] == 1)
	{
		ans += 8;
	}

	cout << ans;

	return 0;
}