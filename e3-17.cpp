#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, n, t, sum;
    cout << "Please input a:";
    cin >> a;
    cout << "Please input n:";
    cin >> n;
    sum = 0; t = 0;
    for (int i = 1; i < n; i++) {
        t   += a * pow(10, i);
        sum += t;
    }
    cout << sum << endl;
    return 0;
}
