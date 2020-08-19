#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[100];

int checking(int num)
{

	int half = sqrt(num);
	for (int j = 2; j <= half; j++)
	{
		if ((num % j) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1) continue;
		ans += checking(arr[i]);
	}

	cout << ans;

	return 0;

}