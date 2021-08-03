#include<iostream>
using namespace std;

namespace one {
    void sum(int a, int b) {
        int c = a*a + b*b;
        cout<<"inside namespace one "<<c<<endl;
    }
}

namespace two {
    void sum(int m, int n) {
        cout<<"inside namespace two "<<m + n;
    }
}

int main() {
    int num1, num2;
    cin>>num1>>num2;
    one::sum(num1, num2);
    two::sum(num1, num2);
    return 0;
}