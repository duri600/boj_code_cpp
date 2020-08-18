#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map<int, vector<int>> graph;
int sum[500][500];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int a;
			cin >> a;
			graph[i].push_back(a);
		}
	}

	sum[0][0] = graph[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				sum[i][j] = sum[i - 1][j] + graph[i][j];
			}
			else if (j == i)
			{
				sum[i][j] = sum[i - 1][j - 1] + graph[i][j];
			}
			else
			{
				sum[i][j] = max(sum[i - 1][j - 1] + graph[i][j], sum[i - 1][j] + graph[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum[n - 1][i] >= ans)
		{
			ans = sum[n - 1][i];
		}
	}

	cout << ans;

	return 0;
}