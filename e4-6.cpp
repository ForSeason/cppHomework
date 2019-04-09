#include <iostream>
#include <cmath>
using namespace std;

class Solution {

    protected:
        double a, b, c, d;

        double newton(double x, double rx){
            double res;
            res = x - f(x) / f1(x);
            return (abs(x - res) <= rx)? res: newton(res, rx);
        }

        double f(double x) {
            return this->a * pow(x, 3) + this->b * pow(x, 2) + this->c * x + this->d;
        }

        double f1(double x) {
            return 3 * this->a * pow(x, 2) + 2 * this->b * x + c;
        }

    public:
        int run() {
            cout << "Please input a, b, c, d: ";
            cin  >> a >> b >> c >> d;
            cout << newton(1.0, 0.000001) << endl;
            return 0;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
