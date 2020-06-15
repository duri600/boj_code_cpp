#include <iostream>
#include <vector>
#include <map>
using namespace std;

int A, B, C;
int D;
map<int, vector<int>> number;

void InputData() {
	cin >> A >> B >> C;
}

void Processing() {
	D = A * B * C;
	int spare;
	int temp;
	int devide;
	temp = D;
	for (int i = 0; i < 10; i++)
	{
		if (temp > 0)
		{
			spare = temp % 10;
			temp = temp / 10;
			number[spare].push_back(1);

		}
	}
}

void result() {
	for (int i = 0; i < 10; i++)
	{
		cout << number[i].size() << endl;
	}
}

int main(void) {

	InputData();

	Processing();

	result();

	return 0;
}