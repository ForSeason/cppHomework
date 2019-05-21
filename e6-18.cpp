#include <iostream>

class Solution {

    public:
        int run() {
            input();
            if (check_input()) {
                output();
                return 0;
            } else {
                std::cout << "error!" << std::endl;
                return 1;
            }
        }

        Solution() {
            for (int i = 1; i < 13; i++) months[i] = (std::string *)malloc(sizeof(std::string));
            *months[1]  = "January";
            *months[2]  = "February";
            *months[3]  = "March";
            *months[4]  = "April";
            *months[5]  = "May";
            *months[6]  = "June";
            *months[7]  = "July";
            *months[8]  = "August";
            *months[9]  = "September";
            *months[10] = "October";
            *months[11] = "November";
            *months[12] = "December";
            return;
        }

    protected:
        std::string *months[13];
        int n;

        void input() {
            std::cin >> n;
            return;
        }

        bool check_input() {
            return (n < 1 || n > 12)? false: true;
        }

        void output() {
            std::cout << *months[n] << std::endl;
            return;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
