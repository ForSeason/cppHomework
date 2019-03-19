#include <iostream>
using namespace std;

int main() {
    int n, t, sum;
    cout << "Please input n:";
    cin >> n;
    sum = 0; t = 1;
    for (int i = 1; i <= n; i++) {
        t   *= i;
        sum += t;
    }
    cout << sum << endl;
}
