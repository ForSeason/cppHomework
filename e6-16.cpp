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
        char input_str[100];
        char res[100][100];
        int  n = 0;

        void input() {
            std::cin >> input_str;
            return;
        }

        void process() {
            char *start = input_str, *end = input_str, *p;
            while (*start != '\0' && *start != '\n') {
                if (*start < '0' || *start > '9') {
                    start++;
                    continue;
                }
                end = start;
                while (*(end + 1) > '0' && *(end + 1) < '9') {
                    end++;
                }
                p = res[n];
                while (start <= end) {
                    *p = *start;
                    p++;
                    start++;
                }
                *p = '\0';
                n++;
            }
        }

        void output() {
            for (int i = 0; i < n; i++) {
                std::cout << res[i] << std::endl;
            }
        }
};

int main() {
    Solution sol;
    return sol.run();
}
