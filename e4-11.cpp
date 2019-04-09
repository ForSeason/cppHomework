#include <iostream>
using namespace std;

class Solution {
    protected:
        int func(int n) {
            return (n >= 1)? func(n - 1) + n*n: 0;
        }

    public:
        int run(){
            int n;
            cout << "Please input n: ";
            cin  >> n;
            cout << "Result: " << func(n) << endl;
            return 0;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
