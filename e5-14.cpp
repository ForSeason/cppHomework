#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

class Solution {

    public:
        int run() {
            input();
            sort();
            output();
            return 0;
        }

    protected:
        std::string str_list[100];
        int n;

        void input() {
            printf("Please input n: ");
            std::cin >> n;
            getline(std::cin, str_list[0]);
            for (int i = 0; i < n; i++) getline(std::cin, str_list[i]);
            return;
        }

        void output() {
            printf("\n\nResult:\n");
            for (int i = 0; i < n; i++) printf("%s\n", str_list[i].c_str());
            return;
        }

        bool check_input(std::string str) {
            std::regex pattern("[A-Za-z]+");
            return regex_match(str, pattern);
        }

        void sort() {
            std::string temp;
            int length;
            for (int i = 0; i < n; i++) {
                if (!check_input(str_list[i])) {
                    str_list[i] = "Invalid input.";
                    continue;
                }
                temp = str_list[i];
                std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
                length = (int)temp.length();
                for (int j = length; j > 0; j--)
                    for (int k = 0; k < j - 1; k++) if (temp[k] > temp[k + 1]) {
                        swap(temp[k], temp[k + 1]);
                        swap(str_list[i][k], str_list[i][k + 1]);
                    }
            }
            return;
        }

        void swap(char& c1, char& c2) {
            char temp;
            temp = c1;
            c1   = c2;
            c2   = temp;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
