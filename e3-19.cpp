#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (int i = 1; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++) {
                if (i * 100 + j * 10 + k == pow(i, 3) + pow(j, 3) + pow(k, 3)) cout << i * 100 + j * 10 + k << endl;
            }
    return 0;
}
