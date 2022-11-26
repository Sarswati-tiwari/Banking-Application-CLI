// Steps to setup the code :---
//1)You need a c++ compiler or c++ ide to setup the code 
//2) Run the whole code in c++ compiler 
//3) Perform the deired operation on CLI 






// In banking application you can find the code in c++ in which you can do the following things:--
// 1) Create an Account
// 2) Deposit Money to That Account -> In this the client needs to input account Number in which he/she needs to add the amount.
// 3) Withdraw the Amount from the Account -> In this client needs to input account Number in which he/she needs to withdraw the amount.
// 4) Balance -> After entering the Account number the c++ code will return the name of that account number in addition it will also return the balance amount. 





#include <iostream>
#include <cstring>
using namespace std;

// class
class Banking {
private:
    char acno[30];
    char name[30];
    long balance=0;

public:
    void OpenAccount()     // It is used to create the account  (Create Account function)
    {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        
    }
    void ShowAccount()   // It is used to show the balance (Balance function)
    {
       
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()   // It is used to Deposit the amount in the Account (Deposit Function)
    {
        long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()   // It is used to Withdraw the amount from the account (Withdraw Function)
    {
        long amt;
        cout << "Enter Amount U want to withdraw? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Less Balance..." << endl;
    }
    
    int search_accno(char *a);
};


int Banking::search_accno(char *a)   // Function to search the things by comparing account number entered by the users.
{
    if(strcmp(acno,a)==0){
        return(1);
    }
    return (0);
}

// main code
int main()
{
    
    
    Banking C[1000];   // Object of class Banking 
    int n=0;
    int found = 0,  ch, i;
    int j=0;
    char a[30];

    do {
        // display options
        cout << "\n\n1:Create\n2:Deposit\n3:Withdraw\n4:Balance\n5:Exit" << endl;

        // user input
        cout << "Please input your choice: ";
        cin >> ch;

        switch (ch) {
            
        case 1: // Create Account
                 C[j].OpenAccount();
                 n++;
                 j++;
                
                
                break;
                
        case 2: // deposit operation
            cout << "Account Number To Deposit Amount? ";
            cin >> a;
            for (i = 0; i < n; i++) {
                found = C[i].search_accno(a);
                if (found) {
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        
        case 3: // withdraw operation
            cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i < n; i++) {
                found = C[i].search_accno(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
            
        case 4: // displaying account info
                cout << "Account Number To Display Balance? ";
                 cin >> a;
                 for (i = 0; i < n; i++) {
                    found = C[i].search_accno(a);
                    if (found) {
                    C[i].ShowAccount();
                    break;
                    }
                }
                if (!found)
                cout << "Record Not Found" << endl;
                break;
        
        
        
        case 5: exit;
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}