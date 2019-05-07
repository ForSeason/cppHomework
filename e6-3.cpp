#include <iostream>

class Solution {

    public:
        int run() {
            input();
            process(list);
            output();
            return 0;
        }

    protected:
        int list[10];

        void input() {
            for (int i = 0; i < 10; i++) {
                std::cin >> *(list + i);
            }
            return;
        }

        void process(int list[]) {
            int *p_max = list, *p_min = list;
            for (int i = 1; i < 10; i++) {
                if (*(list + i) > *p_max) p_max = list + i;
                if (*(list + i) < *p_min) p_min = list + i;
            }
            int temp = *p_max;
            *p_max = *p_min;
            *p_min = temp;
        }

        void output() {
            for (int i = 0; i < 10; i++) {
                std::cout << *(list + i) << ' ';
            }
            std::cout << std::endl;
            return;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
