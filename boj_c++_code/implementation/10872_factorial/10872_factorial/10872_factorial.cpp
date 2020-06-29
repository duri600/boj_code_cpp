#include <iostream>
using namespace std;

int N;
void InputData() {
	cin >> N;
}

int Processing() {

	int ans = 1;
	while (N != 0) {
		ans = ans * N;
		N--;
	}
	return ans;
}

int main(void) {
	InputData();
	
	cout << Processing() << endl;

	return 0;

}