#include <iostream>
using namespace std;

class cl {
    static int resource;  // Shared resource among all objects

public:
    int get_resource();
    void free_resource() { resource = 0; }
};

int cl::resource;  // Define static member

int cl::get_resource() {
    if (resource)
        return 0;  // Resource already in use
    else {
        resource = 1;
        return 1;  // Resource allocated to this object
    }
}

int main() {
    cl ob1, ob2;

    if (ob1.get_resource())
        cout << "ob1 has resource\n";
    if (!ob2.get_resource())
        cout << "ob2 denied resource\n";

    ob1.free_resource();  // Let someone else use it

    if (ob2.get_resource())
        cout << "ob2 can now use resource\n";
    while(1){
        cout<<"infinite"<<endl;

    }

    return 0;
}

