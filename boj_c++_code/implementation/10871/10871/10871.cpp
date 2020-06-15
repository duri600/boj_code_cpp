#include <iostream>
#include <vector>
using namespace std;

int N;
int X;
int A[10010];
vector<int> ans_q;

void InputData() {
	cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
}

void compareData() {
	for (int i = 0; i < N; i++)
	{
		if (A[i] < X)
		{
			ans_q.push_back(A[i]);
		}
	}
}

int main(void) {
	InputData();

	compareData();

	for (auto n : ans_q)
		cout << n << " ";

	return 0;
}