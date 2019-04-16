#include <iostream>
#include <cmath>

class Solution {

    public:
        int run() {
            printf("%s", "Please input a, b, c, d: ");
            scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
            printf("%f\n", newton(1.0, 0.000001));
            return 0;
        }

    protected:
        double a, b, c, d;

        double newton(double x, double rx) {
            double res;
            res = x - f(x)/f1(x);
            return (std::abs(x - res) <= rx)? res: newton(res, rx);
        }

        double f(double x) {
            return this->a * pow(x, 3) + this->b * pow(x, 2) + this->c * x + this->d;
        }

        double f1(double x) {
            return 3 * this->a * pow(x, 2) + 2 * this->b * x + c;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
