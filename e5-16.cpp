#include <iostream>

class Solution {

    public:
        int run() {
            input_char();
            inverse_char(in_char);
            std::cout<<in_char<<std::endl;
            input_str();
            inverse_str(in_str);
            std::cout<<in_str<<std::endl;
            return 0;
        }

    protected:
        std::string in_str;
        char in_char[1000];
        int  n_char;
        int  n_str;

        void input_str() {
            std::cin >> in_str;
            n_str = (int)in_str.length() - 1;
            return;
        }

        void input_char() {
            int  i = -1;
            do {
                i++;
                scanf("%c", &in_char[i]);
            } while (in_char[i] != '\n');
            n_char = i;
            return;
        }

        void inverse_char(char in_char[]) {
            char temp;
            for (int i = 0; i <= n_char / 2; i++) {
                temp = in_char[i];
                in_char[i] = in_char[n_char - i];
                in_char[n_char - i] = temp;
            }
        }

        void inverse_str(std::string &in_str) {
            char temp;
            for (int i = 0; i <= n_str / 2; i++) {
                temp = in_str[i];
                in_str[i] = in_str[n_str - i];
                in_str[n_str - i] = temp;
            }
        }
};

int main() {
    Solution sol;
    return sol.run();
}
