#include <iostream>
#include <algorithm>
using namespace std;

int N[5];
void InputData() {
	for (int i = 0; i < 5; i++)
	{
		cin >> N[i];
	}
}

int Processing() {
	int buger = 0;
	int soda = 0;
	buger = min(N[0], min(N[1], N[2]));
	soda = min(N[3], N[4]);

	return buger + soda;
}

int main(void) {
	InputData();

	int ans = Processing();

	cout << ans - 50 << endl;

	return 0;
}