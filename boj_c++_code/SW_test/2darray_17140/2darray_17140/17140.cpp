#include <iostream>
#include <vector>

using namespace std;

int r, c, k;
int arr_map[100][100];
int row_size = 3;
int col_size = 3;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr_map[i][j];
		}
	}

	while (1)
	{
		//row calc
		if (row_size >= col_size)
		{
			for (int row = 0; row < row_size; row++)
			{
				vector<int> v;
				for (int col = 0; col < col_size; col++)
				{
					v.push_back(arr_map[row][col]);
				}

			}
		}
		else // col calc
		{

		}
	}
	
}