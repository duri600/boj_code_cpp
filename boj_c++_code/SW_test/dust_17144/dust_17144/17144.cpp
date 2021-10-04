#include <iostream>
#include <queue>
using namespace std;


int R, C, T;
int air[50][50] = { 0, };
int air_cleaner[2];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	int air_cnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> air[i][j];
			if (air[i][j] == -1)
			{
				air_cleaner[air_cnt] = i;
				air_cnt++;
			}
		}
	}

	for (int time = 0; time < T; time++)
	{
		int new_air[50][50] = { 0, };
		//diffuse
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (air[i][j] == 0 || air[i][j] == -1)
				{
					continue;
				}

				int diffuse_dust = air[i][j] / 5;
				int dir_cnt = 0;
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = i + dr[dir];
					int nc = j + dc[dir];
					if (air[nr][nc] == -1 || nr == R || nc == C || nr < 0 || nc < 0)
					{
						continue;
					}

					new_air[nr][nc] += diffuse_dust;
					dir_cnt++;
				}
				new_air[i][j] = new_air[i][j] - dir_cnt * diffuse_dust;


			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				air[i][j] += new_air[i][j];
			}
		}


		//clean
		//upper air_cleaner[0]
		for (int row = air_cleaner[0] - 1; row > 0; row--)
		{
			air[row][0] = air[row - 1][0];
		}

		for (int col = 0; col < C - 1; col++)
		{
			air[0][col] = air[0][col + 1];
		}

		for (int row = 0; row < air_cleaner[0]; row++)
		{
			air[row][C - 1] = air[row + 1][C - 1];
		}

		for (int col = C - 1; col > 1; col--)
		{
			air[air_cleaner[0]][col] = air[air_cleaner[0]][col - 1];
		}
		air[air_cleaner[0]][1] = 0;
		air[air_cleaner[0]][0] = -1;

		//lower air_cleaner[1]
		for (int row = air_cleaner[1] + 1; row < R - 1; row++)
		{
			air[row][0] = air[row + 1][0];
		}

		for (int col = 0; col < C - 1; col++)
		{
			air[R - 1][col] = air[R - 1][col + 1];
		}

		for (int row = R - 1; row > air_cleaner[1]; row--)
		{
			air[row][C - 1] = air[row - 1][C - 1];
		}


		for (int col = C - 1; col > 1; col--)
		{
			air[air_cleaner[1]][col] = air[air_cleaner[1]][col - 1];
		}
		air[air_cleaner[1]][1] = 0;
		air[air_cleaner[1]][0] = -1;
	}
	int ans = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ans += air[i][j];
		}
	}
	cout << ans + 2;
	return 0;
}