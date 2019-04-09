#include <iostream>
using namespace std;

class Solution {
    protected:
        double sinh(double x) {
            return (exp(x) - exp(-x)) / 2.0;
        }
        
        double exp(double x) {
            double res = 0;
            for (int i = 0; i <= 10; i++) res += pow(x, i) / fac(i);
            return res;
        }
        
        double pow(double x, int i) {
            double res = 1;
            for (int j = 1; j <= i; j++) res *= x;
            return res;
        }
        
        double fac(int x) {
            return (x > 1)? x * fac(x - 1): 1;
        }
    
    public:
        int run() {
            double x;
            cout << "Please input x: ";
            cin  >> x;
            cout << "sinh(x) = " << sinh(x) << endl;
            return 0;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
