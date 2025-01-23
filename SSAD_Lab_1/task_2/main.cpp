#include <iostream>

using namespace std;

void swapUsingPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b;
    cin >> a >> b;
    swapUsingPointer(&a, &b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    int c, d;
    cin >> c >> d;
    swapUsingReference(c, d);
    cout << "After swapping: c = " << c << ", d = " << d << endl;
    return 0;
}
