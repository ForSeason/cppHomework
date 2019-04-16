#include <iostream>
#include <vector>

class Solution {

    public:
        int run() {
            init();
            SoE();
            output();
            return 0;
        }


    protected:
        struct num {
            int value;
            bool isPrime = true;
        };
        num list[100];

        void init() {
            for (int i = 1; i < 100; i++) list[i].value = i + 1;
            return;
        }

        // sieve of Eratothenes
        void SoE() {
            for (int i = 1; i < 99; i++)
                for (int j = i + 1; j < 100; j++)
                    if (list[j].value % list[i].value == 0) list[j].isPrime = false;
            return;
        }

        void output() {
            for (int i = 1; i < 100; i++) if (list[i].isPrime) printf("%d\n", list[i].value);
            return;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
