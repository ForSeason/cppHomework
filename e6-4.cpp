#include <iostream>

class Solution {

    public:
        int run() {
            input();
            process();
            output();
            return 0;
        }

    protected:
        int m, n;
        int list[1000];

        void input() {
            std::cout << "Please input n:";
            std::cin  >> n;
            std::cout << "Please input m:";
            std::cin  >> m;
            std::cout << "Please input list:";
            for (int i = 0; i < n; i++) std::cin >> *(list + i);
            return;
        }
        
        void process() {
            int temp[1000];
            for (int i = 0; i < m; i++) *(temp + i) = *(list + i + n - m);
            for (int i = n - 1; i >= m; i--) *(list + i) = *(list + i - m);
            for (int i = 0; i < m; i++) *(list + i) = *(temp + i);
        }

        void output() {
            std::cout << std::endl;
            for (int i = 0; i < n; i++) std::cout << *(list + i) << ' ';
            std::cout << std::endl;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
