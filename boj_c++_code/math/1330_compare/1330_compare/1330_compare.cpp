#include <iostream>
using namespace std;

int comp_val(int a, int b)
{
	if (a > b)
	{
		return 0;
	}
	else if (a < b)
	{
		return 1;
	}
	else if (a == b)
	{
		return 2;
	}
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	int ans = comp_val(a, b);
	switch (ans)
	{
	case 0:
		cout << ">" << endl;
		break;
	case 1:
		cout << "<" << endl;
		break;
	case 2:
		cout << "==" << endl;
		break;
	default:
		break;
	}
	return 0;
}