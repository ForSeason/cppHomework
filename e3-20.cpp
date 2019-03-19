#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int sum, n, a[100];
    for (int i = 2; i <= 1000; i++) {
        sum  = 1;
        n    = 0;
        for (int j = 2; j <= i / 2.0; j++) if (i % j == 0) {
            sum += j;
            a[n] = j;
            n++;
        }
        if (sum == i) {
            cout << i <<" ,its factors are ";
            for (int i = 0; i < n - 1; i++) cout << a[i] << ",";
            cout << a[n-1] << endl;
        }
    }
    return 0;
}
