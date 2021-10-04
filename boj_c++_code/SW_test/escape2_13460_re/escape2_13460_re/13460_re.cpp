#include <iostream>

using namespace std;

struct pos {
	int row;
	int col;
};

int N, M;
int board[10][10];
pos R;
pos B;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

int ans = 99;

//dir 0, 1, 2, 3

int inverse_dir(int dir)
{
	if (dir == 0)
	{
		return 1;
	}
	else if (dir == 1)
	{
		return 0;
	}
	else if (dir == 2)
	{
		return 3;
	}
	else if (dir == 3)
	{
		return 2;
	}
}

void dfs(int rr, int rc, int br, int bc, int length, int dir_ind)
{
	if (length >= ans) return;
	if (length > 10) return;

	bool b_hole_check = false;
	bool r_hole_check = false;
	pos cur_r;
	cur_r.row = rr + dr[dir_ind];
	cur_r.col = rc + dc[dir_ind];
	while (1)
	{
		if (board[cur_r.row][cur_r.col] == -1)
		{
			break;
		}

		if (board[cur_r.row][cur_r.col] == 2)
		{
			r_hole_check = true;
			break;
		}
		cur_r.row = cur_r.row + dr[dir_ind];
		cur_r.col = cur_r.col + dc[dir_ind];
	}
	cur_r.row = cur_r.row - dr[dir_ind];
	cur_r.col = cur_r.col - dc[dir_ind];

	pos cur_b;
	cur_b.row = br + dr[dir_ind];
	cur_b.col = bc + dc[dir_ind];
	while (1)
	{

		if (board[cur_b.row][cur_b.col] == -1)
		{
			break;
		}

		if (board[cur_b.row][cur_b.col] == 2)
		{
			b_hole_check = true;
			break;
		}
		cur_b.row = cur_b.row + dr[dir_ind];
		cur_b.col = cur_b.col + dc[dir_ind];
	}
	cur_b.row = cur_b.row - dr[dir_ind];
	cur_b.col = cur_b.col - dc[dir_ind];

	if (b_hole_check)
	{
		return;
	}
	else
	{
		if (r_hole_check)
		{
			if (ans > length)
			{
				ans = length;
			}
			return;
		}
	}

	if (cur_r.row == cur_b.row && cur_r.col == cur_b.col)
	{
		int dist_r = abs(cur_r.row - rr) + abs(cur_r.col - rc);
		int dist_b = abs(cur_b.row - br) + abs(cur_b.col - bc);

		if (dist_r > dist_b)
		{
			cur_r.row = cur_r.row - dr[dir_ind];
			cur_r.col = cur_r.col - dc[dir_ind];
		}
		else
		{
			cur_b.row = cur_b.row - dr[dir_ind];
			cur_b.col = cur_b.col - dc[dir_ind];
		}

	}

	for (int i = 0; i < 4; i++)
	{
		if (i == dir_ind)
		{
			continue;
		}
		if (i == inverse_dir(dir_ind))
		{
			continue;
		}
		dfs(cur_r.row, cur_r.col, cur_b.row, cur_b.col, length + 1, i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			char temp;
			cin >> temp;
			if (temp == '#')
			{
				board[r][c] = -1;
			}
			else if (temp == 'R')
			{
				board[r][c] = 0;
				R.row = r;
				R.col = c;
			}
			else if (temp == 'B')
			{
				board[r][c] = 0;
				B.row = r;
				B.col = c;
			}
			else if (temp == 'O')
			{
				board[r][c] = 2;
			}
			else
			{
				board[r][c] = 0;
			}
		}
	}


	for (int i = 0; i < 4; i++)
	{
		dfs(R.row, R.col, B.row, B.col, 1, i);
	}

	if (ans > 10 || ans == 99)
	{
		ans = -1;
	}

	cout << ans << endl;


	return 0;

}