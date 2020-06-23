#include <iostream>
using namespace std;

int T;
int N;
int main(void) {
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
    }
}

int fibonacci(int n) {
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
    else if(n == 1)
    {
        cout << "1" << endl;
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}