#include <iostream>
using namespace std;

int k;
int num_array[13];
int visit[13];

void make_lotto(int start, int depth) {
	if (depth == 6) {
		for (int j = 0; j < k; j++)
		{
			if (visit[j] == 1)
			{
				cout << num_array[j] << " ";
			}
		}
		cout << endl;
	}
	else
	{
		for (int i = start; i < k; i++)
		{
			if (visit[i] == 1)
			{
				continue;
			}
			visit[i] = 1;
			make_lotto(i, depth + 1);
			visit[i] = 0;
		}
	}
	
}

int main(void) {
	while (true)
	{
		cin >> k;
		if (k == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				cin >> num_array[i];
				visit[i] = 0;
			}
			make_lotto(0, 0);

			cout << endl;

		}
	}
	return 0;
}