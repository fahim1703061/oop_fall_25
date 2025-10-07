#include <iostream>
#include <cstdlib>
using namespace std;
class Account {
   private:

    long long int acc_no;
    double balance;

   public:

    string name;

    Account()
    {
        cout<< "---- Create a Account ----" << endl;
    }

    Account(string name, long long int acc_no, double balance)
    {
        cout<< "---- Create a Account ----" << endl;
        this-> name = name;
        this->acc_no = acc_no;
        this->balance = balance;
    }
    ~Account()
    {
        cout <<"\n\nFinal state: "<<endl;
        display();
        cout <<"\n\nYour account is being deleted :'(\n" <<endl;
    }
    void set_acc_no(long long int acc_no);
    void set_balance(double balance);

    double get_balance();

    void deposit(float amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void deposit(float amount, string Remarks) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
        display();
        cout <<Remarks<<endl;
    }
    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
    void display() const {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << acc_no << endl;
        cout << "Balance: " << balance << endl;
    }
};

void Account::set_acc_no(long long int acc_no)
{
    this->acc_no = acc_no;
}
void Account::set_balance(double balance)
{
    this->balance = balance;
}
double Account::get_balance()
{
    return balance;
}


int main()
{
    cout<<"------ Hexa Bank ------"<<endl;

    Account testAcc;

    testAcc.name = "Arman";
    //testAcc.acc_no = 01012510005101005;
    testAcc.set_acc_no(1012510005101008);
    testAcc.set_balance(200);

    testAcc.display();

    testAcc.deposit(100);
    testAcc.display();



    //system("clear");
    cout<<endl<<endl;
    testAcc.deposit(40000, "Salary Aug'2025");

    Account testAcc2("Romiz", 1012510005101002, 50000);
    testAcc2.display();

    //getter function example

    cout <<"\n\n";
    cout << "All Accounts info.:\n";
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout <<"\n\n";
    cout <<"Account Name    | Balance      \n";
    cout <<"~~~~~~~~~~~~~~~ | ~~~~~~~  \n";
    cout <<testAcc.name<<"  |  "<<testAcc.get_balance()<<"  "<<endl; //double precision format
    cout <<testAcc2.name<<"  |  "<<testAcc2.get_balance()<<"  "<<endl;

    return 0;
}
