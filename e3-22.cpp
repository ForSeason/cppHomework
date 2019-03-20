#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, x, temp;
    cout << "Please input a: ";
    cin >> a;
    x = a;
    do {
        temp = (x + a / x) / 2.0;
        if (abs(temp - x) < 1e-5) break;
        x = temp;
    } while (1);
    cout << "x = " << x << endl;
    return 0;
}
