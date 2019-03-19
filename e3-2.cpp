#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double r = 1.5, h = 3, pi = 3.1415;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout << "圆面积: " << pi * pow(r, 2) << endl;
    cout << "圆周长: " << 2 * pi * r << endl;
    cout << "球面积: " << 4 * pi * pow(r, 2) << endl;
    cout << "球体积: " << 4 / 3 * pi * pow(r, 3) << endl;
    cout << "柱体积: " << pi * pow(r, 2) * h << endl;
}
