#include <iostream>
using namespace std;

int ans[41];

int fibonacci(int n) {

	if (n <= 1) {
		return ans[n] = 1;
	}
	else
	{
		if (ans[n] > 0)
		{
			return ans[n];
		}
	}


	return ans[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int T;
int N;
int main(void) {
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N == 0) {
			cout << "1" << " " << "0" << endl;
		}

		else if (N == 1) {
			cout << "0" << " " << "1" << endl;
		}

		else
		{
			cout << fibonacci(N - 2) << " " << fibonacci(N - 1) << endl;
		}

	}

	return 0;
}

