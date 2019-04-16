#include <iostream>

class Solution {

    public:
        int run() {
            int mat[10][10];
            int temp;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j <= i; j++) {
                    temp = (j == 0 || j == i)? 1: mat[i - 1][j] + mat[i - 1][j - 1];
                    mat[i][j] = temp;
                    printf("%d ", temp);
                }
                printf("\n");
            }
            return 0;
        }
};

int main() {
    Solution sol;
    return sol.run();
}
