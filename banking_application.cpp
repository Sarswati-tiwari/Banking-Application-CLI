#include <iostream>
#include <cstring>
using namespace std;

// class
class Bank {
private:
    char acno[30];
    char name[30];
    long balance=0;

public:
    void OpenAccount()
    {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        
    }
    void ShowAccount()
    {
       
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
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


int Bank::search_accno(char *a)
{
    if(strcmp(acno,a)==0){
        return(1);
    }
    return (0);
}

// main code
int main()
{
    
    
    Bank C[1000];
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
            
        case 1: C[j].OpenAccount();
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
            
        case 4: // displating account info
                cout << "Account Number To Withdraw Amount? ";
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