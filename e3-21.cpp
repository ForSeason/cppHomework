#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n > 2) {
        return fib(n - 1) + fib(n - 2);
    } else {
        return 0;
    }
}

int main() {
    return 0;
}
