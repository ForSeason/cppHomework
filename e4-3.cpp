#include <iostream>
#include <cstring>

using namespace std;

bool check(int x) {
    int i;
    for (i = 2; i <= x / 2; i++) if (x % i == 0) return false;
    return true;
}

int main() {
    int in;
    string out;
    cout << "请输入一个整数: ";
    cin >> in;
    out = (check(in))? "是": "否";
    cout << out << endl;
    return 0;
}
