#include <iostream>
#include <algorithm>
using namespace std;


int N;
int RGB[1001][3] = { 0 };

void InputData() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
}

int main(void) {

	InputData();

	for (int i = 1; i <= N; i++)
	{
		RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][1], RGB[i - 1][0]);
	}

	cout << min(RGB[N][0], min(RGB[N][1], RGB[N][2])) << endl;

	return 0;
}