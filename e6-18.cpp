#include <iostream>

class Solution {

    public:
        int run() {
            input();
            output();
            return 0;
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

        void output() {
            std::cout << *months[n] << std::endl;
            return;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
