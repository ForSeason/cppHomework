#include <iostream>
#include <cmath>
using namespace std;

void equal0(double a, double b) {
    cout << "x1 = x2 = " << -b / a / 2.0 << endl;
    return;
}


void over0(double a, double b, double delta) {
    cout << "x1 = " << (-b + sqrt(delta)) / a / 2.0 << endl;
    cout << "x2 = " << (-b - sqrt(delta)) / a / 2.0 << endl;
    return;
}

void below0(double a, double b, double delta) {
    cout << "x1 = " << -b / a / 2.0 << '+' << sqrt(abs(delta)) / a / 2.0 << 'i' << endl;
    cout << "x2 = " << -b / a / 2.0 << '-' << sqrt(abs(delta)) / a / 2.0 << 'i' << endl;
    return;
}

int main() {
    double a, b, c, delta;
    cout << "Please input a, b, c: ";
    cin >> a >> b >> c;
    delta = pow(b, 2) - 4 * a * c;
    if (delta == 0) equal0(a, b);
    else if (delta > 0) over0(a, b, delta);
    else below0(a, b, delta);
    return 0;
}
