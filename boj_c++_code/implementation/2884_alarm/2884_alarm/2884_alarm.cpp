#include <iostream>
using namespace std;

int H, M;

void InputData() {
	cin >> H >> M;
}

int main(void) {
	InputData();
	int hour, min;
	if (M < 45)
	{
		min = M + 60 - 45;
		if (H - 1 < 0) {
			hour = H - 1 + 24;
		}
		else
		{
			hour = H - 1;
		}
	}
	else
	{
		hour = H;
		min = M - 45;
	}
	cout << hour << " " << min;
	return 0;
}