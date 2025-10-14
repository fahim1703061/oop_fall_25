#include <iostream>
#include <cstdlib>
#include <cstdio>
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

//    home task
//    define transfer function void transfer(toAcc, amount)

    void transfer(Account toAcc, double amount);

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

void Account::transfer(Account toAcc, double amount)
{
    if (amount > 0 && amount <= balance) {
            balance -= amount;
            toAcc.balance+=amount;
            cout << "\n\nFund Transferred Tk. " << amount <<"| Sender Name: "<< name<<"| Receiver Name: "<< toAcc.name<< endl;
            cout <<"\n\nFund Transfer Successful.\n";
            display();
        } else {
            cout << "\n\nTransfer Failed. Insufficient balance or Invalid amount" << endl;
        }

}

string classify_category(Account acc)
{
    double temp_balance = acc.get_balance();

    if (temp_balance>10000){
        return "Diamond";
    }
    else{
        return "Gold";
    }
}



string round(double var, int p=2)
{
    // we use array of chars to store number
    // as a string.
//    cout<<var<<"\n";
    char str[40];

    char m =p + '0';
	const char output[5] = {'%', '.',m,'f','\0'}; //"0.pf"
    // Print in string the value of var
    // with two decimal point
//    sprintf(str, "%.2f", var);
    sprintf(str, output, var);
    // scan string value in var
//    sscanf(str, "%f", &var);

    return str;
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

    Account testAcc2("Romiz", 1012510005101002, 50000.52);
    testAcc2.display();

    Account testAcc3;
    testAcc3 = testAcc2;
    testAcc3.name = "Iftekhar";
    testAcc3.display();

    //getter function example

//    task 1: Create 1d array with 5 objects, use parameterized constructor

    Account accArray[5] = {
    {"Noman", 1012510005101017, 15000},
    {"Rifa", 1012510005101002, 9000},
    {"Fahim", 1012510005101007, 12000},
    {"Tasnim", 1012510005101006, 7000},
    {"Dewan", 1012510005101008, 25000}
    };
//    task 2: create 2d array [4][2],  use parameterized constructor

    Account acc2D[4][2] = {
    { Account("Ashik", 1012510005102015, 5000), Account("Arisha", 1012510005102014, 11000) },
    { Account("Jisan", 1012510005102010, 25000), Account("Udoy", 1012510005102004, 8000) },
    { Account("Mahi", 1012510005102003, 15000), Account("Jony", 10125100051020019, 6000) },
    { Account("Jony", 1012510005102020, 10000), Account("Momo", 1012510005102018, 30000) }
    };

    cout <<"\n\n";
    cout << "All Accounts info.:\n";
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout <<"\n\n";
    cout <<"Account Name    | Balance    |  Account Type  \n";
    cout <<"~~~~~~~~~~~~~~~ | ~~~~~~~ ~~~| ~~~~~~~~~~~~~~ \n";
    cout <<testAcc.name<<"  |  "<<round(testAcc.get_balance())<<"  "<<endl; //category removed
    cout <<testAcc2.name<<"  |  "<<round(testAcc2.get_balance(), 4)<<"  "<<endl;

    //task1 output

//    cout << "\n\n--- Task 1: 1D Array of Accounts ---\n\n";
    for (int i = 0; i < 5; i++) {
        cout <<accArray[i].name<<"  |  "<<round(accArray[i].get_balance(),2)<<"  "<<endl;
    }
//    task 2 output
//    cout << "\n\n--- Task 2: 2D Array of Accounts ---\n\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout <<acc2D[i][j].name<<"  |  "<<round(acc2D[i][j].get_balance(),2)<<"  "<<endl;

        }
    }

    testAcc.transfer(testAcc2, 5000);
//    cout

    return 0;
}
