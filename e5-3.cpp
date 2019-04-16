#include <iostream>

class Solution {

    public:
        int run() {
            input();
            printf("Result: %lf", sum());
            return 0;
        }

    protected:
        double mat[3][3];

        void input() {
            printf("Please input the matrix:\n");
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    scanf("%lf", &mat[i][j]);
        }

        double sum() {
            return mat[0][0] + mat[2][0] + mat[2][2] + mat[0][2] + mat[1][1]; 
        }
};

int main() {
    Solution sol;
    return sol.run();
}
