#include <iostream>
using namespace std;

int main() {
    char in[20];
    cin>>in;
    for (int i = 0; i < 5; i++) {
        in[i] += 4;
        cout<<in[i];
    }
    cout<<endl;
    return 0;
}
