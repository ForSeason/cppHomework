#include <iostream>

class Solution {
    
    public:
        int run() {
            double x;
            printf("%s", "Please input x: ");
            scanf("%lf", &x);
            printf("sinh(x) = %f\n", sinh(x));
            return 0;
        }
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
};

int main() {
    Solution sol;
    return sol.run();
}
