#include <iostream>
using namespace std;

int M;
int D;
int days = 0;

void InputData() {
	cin >> M >> D;
}

void CalcDate() {
	if (M == 1)
	{
		days = 0;
		
	}
	else
	{
		for (int i = 1; i < M; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				days += 31;
			}
			else if (i == 2) {
				days += 28;
			}
			else
			{
				days += 30;
			}
		}
	}

	days = days + D;

	switch (days % 7)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	default:
		break;
	}
}

int main(void) {
	InputData();

	CalcDate();

	return 0;

}