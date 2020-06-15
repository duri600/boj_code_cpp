#include <iostream>
#include <vector>
using namespace std;

int N;

void InputData() {
	cin >> N;
}

int sugar() {
	int a, b, c, d;
	
	a = N / 5;
	b = N % 5;
	c = 0;
	d = 0;
	for (int i = 0; i < 3; i++)
	{
		if (a >= i) {
			c = N - (a - i) * 5;
			if ((c % 3) == 0)
			{
				d = c / 3;
				return d + a - i;
			}
		}
	}
	
	return -1;
		
}

int main(void) {
	int ans;
	InputData();
	ans = sugar();

	cout << ans;

	return 0;
}