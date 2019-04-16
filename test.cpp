#include <iostream>
#include <vector>

class Solution {

    public:
        int run() {
            int n;
            printf("请输入数组长度：\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) intMat.push_back(std::vector<int>);
            for (auto intList:intMat) for (auto i:intList) i = 1;
            printf("\n");
            return 0;
        }

    protected:
        std::vector<std::vector<int>> intMat;
};

int main() {
    Solution sol;
    return sol.run();
}
