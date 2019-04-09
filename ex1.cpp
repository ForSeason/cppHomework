#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;

class Solution {

    protected:
        int char_n2dec(char in) {
            return ('A' <= in && in <= 'Z')? (int)(in - 'A' + 10): (int)(in - '0');
        }

        string char_dec2n(long int in) {
            char tmp;
            string res;
            tmp = (in < 10)? (char)('0' + in): (char)('A' + in - 10);
            stringstream sss;
            sss << tmp;
            return sss.str();
        }

        string n2dec(string in, int n) {
            long int sum = 0;
            int len = (int)in.length();
            for (int i = 0; i < len; i++) sum += char_n2dec(in[len - i - 1]) * pow(n, i);
            return to_string(sum);
        }

        string dec2n(string in, int n) {
            string res = "";
            long int temp;
            istringstream iss(in);
            iss >> temp;
            do {
                res   = char_dec2n(temp % n) + res;
                temp /= n;
            } while (temp);
            return res;
        }

        bool check_input(string in_str, int in, int out) {
            if (!(2 <= in && in <= 36) || !(2 <= out && out <= 36)) {
                return false;
            } else {
                string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                regex pattern("[" + dict.substr(0, in) + "]+");
                return regex_match(in_str, pattern);
            }
        }

        void input(string& in_str, int& in, int& out) {
            cout << "请输入要转换的数字(最大36进制, 仅支持正整数): ";
            getline(cin, in_str);
            cout << "请输入原本数字的进制: ";
            cin  >> in;
            cout << "请输入要输入的数字的进制: ";
            cin  >> out;
        }

    public:
        int run() {
            int in, out;
            string in_str;
            input(in_str, in, out);
            if (check_input(in_str, in, out)) {
                cout << "结果: " << dec2n(n2dec(in_str, in), out) << endl;
                return 0;
            } else {
                cout << "非法输入!" << endl;
                return 403;
            }
        }
};

int main() {
    Solution sol;
    return sol.run();
}
