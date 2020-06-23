#include <iostream>
using namespace std;


int n;
int ans[1001];

int tiling(int n) {
	if (n == 1)
	{
		return ans[n] = 1;
	}
	if (n == 2)
	{
		return ans[n] = 2;
	}
	else {
		if (ans[n] > 0)
		{
			return ans[n];
		}
	}

	return ans[n] = (tiling(n - 1) + tiling(n - 2)) % 10007;
}

int main(void) {
	cin >> n;

	int out = 0;
	out = tiling(n) % 10007;
	cout << out << endl;

	return 0;
}