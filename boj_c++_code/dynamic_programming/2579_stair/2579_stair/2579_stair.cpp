#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[301];
int A[301];
int ans = 0;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
}

int main(void) {
	InputData();
	
	A[0] = S[0];
	A[1] = S[0] + S[1];
	A[2] = max(S[0] + S[2], S[1] + S[2]);
	for (int i = 3; i < N; i++)
	{
		A[i] = max(A[i - 2] + S[i], A[i - 3] + S[i - 1] + S[i]);
	}

	cout << A[N - 1] << endl;

	return 0;

}