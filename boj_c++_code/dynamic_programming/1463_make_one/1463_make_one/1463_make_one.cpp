#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ANS[1000001];
int main(void) {

	cin >> N;

	for (int i = 2; i <= N; i++) {
		ANS[i] = ANS[i - 1] + 1;
		if (i % 2 == 0) {
			ANS[i] = min(ANS[i], ANS[i / 2] + 1);
		}
		if (i % 3 == 0) {
			ANS[i] = min(ANS[i], ANS[i / 3] + 1);
		}
	}

	cout << ANS[N] << endl;

	return 0;
}