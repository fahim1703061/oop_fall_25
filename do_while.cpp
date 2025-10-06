#include <iostream>

using namespace std;

int main()
{
    int correctpin = 3456;
    int enteredpin = -1;
    int isAuth = 0;

    do{
        cout <<"Enter your pin: ";
        cin>>enteredpin;

        if (correctpin == enteredpin){
            cout<<"PIN accepted. Access granted"<<endl;
            isAuth = 1;
        }
        else{
            cout<<"Incorrect PIN. Please try again."<<"\n";

        }
    }while(!isAuth);

    return 0;
}
