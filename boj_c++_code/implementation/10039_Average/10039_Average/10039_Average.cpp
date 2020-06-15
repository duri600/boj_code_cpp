#include <iostream>
using namespace std;

int score[5];

void InputData() {
	
	for (int i = 0; i < 5; i++)
	{
		cin >> score[i];
	}

}

int Processing() {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (score[i] >= 40)
		{
			sum = sum + score[i];
		}
		else
		{
			sum += 40;
		}
	}
	return sum / 5;
}

int main(void) {
	InputData();

	int ans;

	ans = Processing();

	cout << ans;

	return 0;
}