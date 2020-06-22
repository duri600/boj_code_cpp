#include <iostream>
using namespace std;

int T;
int N;
int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		int dp[11];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int j = 4; j <= N; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}

		cout << dp[N] << endl;

	}

	return 0;
}