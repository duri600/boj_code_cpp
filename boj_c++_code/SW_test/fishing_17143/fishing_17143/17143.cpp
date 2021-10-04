#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int R, C, M;
struct SHARK
{
	int speed, dir, size;
};

vector<SHARK> shark_v;
SHARK shark_map[100][100];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,1,-1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	for (int index = 0; index < M; index++)
	{
		SHARK temp;
		int r, c;
		cin >> r >> c >> temp.speed >> temp.dir >> temp.size;
		temp.dir = temp.dir - 1;
		shark_map[r - 1][c - 1] = temp;
	}

	SHARK new_shark_map[100][100];
	int ans = 0;
	for (int time = 0; time < C; time++)
	{
		//fishing
		for (int row = 0; row < R; row++)
		{
			if (shark_map[row][time].size > 0)
			{
				ans += shark_map[row][time].size;
				shark_map[row][time].size = 0;
				break;
			}
		}

		memcpy(new_shark_map, shark_map, sizeof(shark_map));
		memset(shark_map, 0, sizeof(shark_map));
		//moving

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				SHARK cur = new_shark_map[i][j];
				if (cur.size > 0)
				{
					int nr = i + cur.speed * dr[cur.dir];
					int nc = j + cur.speed * dc[cur.dir];
					if (nr < 0)
					{
						nr = -nr;
						cur.dir = 1;
					}
					if (nr > R - 1)
					{
						int a = nr / (R - 1);
						int b = nr % (R - 1);
						if (a % 2 == 0)
						{
							nr = b;
						}
						else
						{
							nr = R - 1 - b;
							cur.dir = 0;
						}
					}

					if (nc < 0)
					{
						nc = -nc;
						cur.dir = 2;
					}
					if (nc > C - 1)
					{
						int a = nc / (C - 1);
						int b = nc % (C - 1);
						if (a % 2 == 0)
						{
							nc = b;
						}
						else
						{
							nc = C - 1 - b;
							cur.dir = 3;
						}
					}

					if (shark_map[nr][nc].size < cur.size)
					{
						shark_map[nr][nc] = cur;
					}
				}
			}
		}


	}

	cout << ans;

	return 0;
}