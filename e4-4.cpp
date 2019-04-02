#include <iostream>

using namespace std;

int fac(int x) {
    return (x <= 1)? 1: x * fac(x - 1);
}

int main() {
    int a, b, c;
    cout << "请输入三个数字的值: ";
    cin >> a >> b >> c;
    cout << "结果: " << fac(a) + fac(b) + fac(c) << endl;
    return 0;
}
