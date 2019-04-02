#include <iostream>
#include <cmath>
using namespace std;


int greatest_common_factor(int in1, int in2) {
    int r, x, y;
    x = (in1 > in2)? in1: in2;
    y = (in1 > in2)? in2: in1;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int least_common_mutiple(int in1, int in2) {
    int gcf;
    gcf = greatest_common_factor(in1, in2);
    return in1 * in2 / gcf;
}

int main() {
    int a, b;
    cout << "Please input 2 integers: ";
    cin >> a >> b;
    cout << "greatest_common_factor: " << greatest_common_factor(a, b) << endl;
    cout << "least_common_mutiple: " << least_common_mutiple(a, b) << endl;
    return 0;
}
