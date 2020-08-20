#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h;
int tot = 0;
vector<int> height;
int visit[9];

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		cin >> h;
		height.push_back(h);
		tot += h;
		visit[i] = 0;
	}
	sort(height.begin(),height.end());

	int diff = tot - 100;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (diff == height[i] + height[j])
			{
				visit[i] = 1;
				visit[j] = 1;
				goto EXIT;
			}
		}
	}

EXIT:
	for (int i = 0; i < 9; i++)
	{
		if (visit[i] == 0)
		{
			cout << height[i] << endl;
		}
	}
	return 0;
}