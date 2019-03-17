#include <iostream>
using namespace std;

int main() {
    int a, b, c, max;
//    cin >> a >> b;
//    max = (a > b)? a: b;
//    cin >> c;
//    max = (max > c)? max: c;
//    cout << c << endl;
    cin >> a >> b >> c;
    cout << ((a > b)? a: ((b > c)? b: c));
    return 0;
}
