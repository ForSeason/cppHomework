#include <iostream>
using namespace std;

int main() {
    char in[5] = {'x', 'x', 'x', 'x', 'x'};
    int i, sum = 0;
    cin>>in;

    for (i = 0; i < 5; i++) {
        if (in[i] <= '9' && in[i] >= '0') {
            sum++;
        } else {
            break;
        }
    }
    cout<<sum<<endl<<endl;

    for (i = 0; i < sum; i++) {
        cout<<in[i]<<endl;
    }
    cout<<endl;

    for (i = 0; i < sum; i++) {
        cout<<in[sum - i - 1]<<endl;
    }

    return 0;
}
