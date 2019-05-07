#include <iostream>
#include <vector>

  /* 
   * 假设成绩60以下即为不及格
   */

class Solution {

    public:
        int run() {
            input();
            output();
            return 0;
        }

    protected:
        struct Student {
            std::string name;
            double score;
            int id;
        };
        const int N = 10;
        std::vector<Student> list;

        void input() {
            Student stu;
            for (int i = 0; i < N; i++) {
                std::cout << "姓名: ";
                std::cin  >> stu.name;
                std::cout << "学号: ";
                std::cin  >> stu.id;
                std::cout << "成绩: ";
                std::cin  >> stu.score;
                std::cout << std::endl;
                list.push_back(stu);
            }
            return;
        }

        void output() {
            std::cout << "以下是不及格者: " << std::endl;
            for (auto stu:list) {
                if (stu.score < 60) {
                    std::cout << "姓名: ";
                    std::cout << stu.name;
                    std::cout << std::endl;
                    std::cout << "学号: ";
                    std::cout << stu.id;
                    std::cout << std::endl;
                    std::cout << "成绩: ";
                    std::cout << stu.score;
                    std::cout << std::endl;
                    std::cout << std::endl;
                }
            }
        }
};

int main() {
    Solution sol;
    return sol.run();
}
