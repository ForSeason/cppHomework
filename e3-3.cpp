#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    double f;
    cout<<"请输入华氏温度: ";
    cin>>f;
    cout<<"对应的摄氏温度为: "<<5.0 / 9.0 * (f - 32)<<endl;
    return 0;
}
