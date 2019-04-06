#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <cmath>
using namespace std;

int char_n2dec(char in) {
    char dict[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < 16; i++) if (dict[i] == in) return i;
    return 1;
}

string char_dec2n(int in) {
    string dict[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    return dict[in];
}

string n2dec(string in, int n) {
    int sum = 0, len = (int)in.length();
    for (int i = 0; i < len; i++) sum += char_n2dec(in[len - i - 1]) * pow(n, i);
    return to_string(sum);
}

string dec2n(string in, int n) {
    string res = "";
    int temp;
    istringstream iss(in);
    iss >> temp;
    do {
        res = char_dec2n(temp % n) + res;
        temp /= n;
    } while (temp);
    return res;
}

bool check_input(string in_str, int in, int out) {
    if (!(2 <= in && in <= 16) || !(2 <= out && out <= 16)) {
        return false;
    } else {
        string dict = "0123456789ABCDEF";
        regex pattern("[" + dict.substr(0, in) + "]+");
        return regex_match(in_str, pattern);
    }
}

void input(int& in, int& out, string& in_str) {
    cout << "input metadata: ";
    getline(cin, in_str);
    cout << "input original system: ";
    cin >> in;
    cout << "input target system: ";
    cin >> out;
}

int main() {
    int in, out;
    string in_str;
    input(in, out, in_str);
    if (check_input(in_str, in, out)) {
        cout << "Result: " << dec2n(n2dec(in_str, in), out) << endl;
    } else {
        cout << "Invalid input!" << endl;
    }
    return 0;
}
