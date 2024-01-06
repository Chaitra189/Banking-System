// Banking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#define acc_size 100
using namespace std;

class BankingSystem {
private:
    string acc_name;
    string phone_num;
    string password;
    int acc_num;
    float acc_balance = 0;
    bool accessGrant = false;

public:
    void Bank_acc()
    {
        srand(time(0));
        cout << "Enter the name:";
        cin >> acc_name;
        cout << "Enter the phone number:";
        cin >> phone_num;
        cout << "create password:";
        cin >> password;
        acc_num = rand();
        cout << "Your account number: " << acc_num << endl;
        cout << "Enter the deposit amount:";
        cin >> acc_balance;
    }
    void Access_acc()
    {
        int temp_acc;
        string temp_pwd;
        cout << "Enter the account number again:";
        cin >> temp_acc;

        cout << "Enter the password:";
        cin >> temp_pwd;

        if (temp_acc == acc_num && temp_pwd == password)
        {
            accessGrant = true;
            cout << "Access granted";
        }
        else
            cout << "Incorrect credentials";
    }
    void Balance()
    {
        if (accessGrant == true)
        {
            cout << "Your account balance is " << acc_balance;
        }
        else
            cout << "Incorrect credentials";
    }
    void Deposit()
    {
        if (accessGrant == true)
        {
            int temp;
            cout << "Enter the amount:";
            cin >> temp;
            acc_balance += temp;
            cout << "Your account balance is " << acc_balance;
        }
        else
            cout << "Incorrect credentials";
    }
    void withDraw()
    {
        if (accessGrant == true)
        {
            int temp;
            cout << "Enter the amount:";
            cin >> temp;
            if (temp <= acc_balance)
            {
                acc_balance -= temp;
                cout << "Your account balance is " << acc_balance;
            }
            else
                cout << "Insufficient balance";
        }
    }
    int acc_number()
    {
        return acc_num;
    }
};

int main()
{   
    bool isRunning = true;
    BankingSystem b[acc_size];
    int acc_itr = 0;
    int choice;
    int acc_grant_itr = NULL;
    cout << "   BANK   ";

    while(isRunning)
    {       
        cout << "  \n\nSelect an option from the choices ";
        cout << "\n1.Create an Account\n";
        cout << "2.Access account\n";
        cout << "3.check balance\n";
        cout << "4.Deposit\n";
        cout << "5.Withdrawal\n";
        cout << "6.Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: b[acc_itr++].Bank_acc();
            break;
        case 2:int temp;
            cout << "Enter the account number:";
            cin >> temp;
            for (int i = 0;i <= acc_itr;i++)
            {
                if (b[i].acc_number() == temp)
                {
                    acc_grant_itr = i;
                    b[acc_grant_itr].Access_acc();
                    break;
                }
            }
            break;
        case 3:b[acc_grant_itr].Balance();
            break;
        case 4:b[acc_grant_itr].Deposit();
            break;
        case 5:b[acc_grant_itr].withDraw();
            break;
        case 6:isRunning = false;
            acc_grant_itr = NULL;
            break;
        default:cout<<"Invalid input";
            acc_grant_itr = NULL; 
            break;
        }
    }
    
    return 0;    
}

