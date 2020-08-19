#include <iostream>
using namespace std;

int N;
int cnt = 0;

int processing(int numb)
{
	int a, b;
	int temp;
	int new_num = 0;
	a = numb % 10;
	b = numb / 10;
	temp = a + b;
	temp = temp % 10;
	new_num = temp + a * 10;
	cnt++;

	while (new_num != N)
	{
		a = new_num % 10;
		b = new_num / 10;
		temp = a + b;
		temp = temp % 10;

		new_num = temp + a * 10;
		cnt++;
	}
	return cnt;
}

int main(void)
{
	cin >> N;

	int ans;

	ans = processing(N);

	cout << ans;

	return 0;
	
}