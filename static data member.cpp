#include <iostream>
using namespace std;

class shared {

    int b;         // Non-static member unique to each object

public:
    static int a;  // Static member shared by all objects
    void set(int i, int j) {
        a = i;
        b = j;
    }
    void show();
};


int shared::a; // Define static member

void shared::show() {
    cout << "This is static a: " << a;
    cout << "\nThis is non-static b: " << b;
    cout << "\n";
}

int main() {
    shared ::a = 10;
    cout<<shared ::a<<endl;;
    shared x, y;
    x.show();
    x.set(1, 1); // Set a to 1
    x.show();
    y.set(2, 2); // Change a to 2
    y.show();
    x.show(); // 'a' has been changed for both x and y because 'a' is shared
    return 0;
}

