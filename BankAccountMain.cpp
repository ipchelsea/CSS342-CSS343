/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "BankAccount.h"
using namespace std;

int main()
{
    BankAccount ba0;
    cout <<"ba0 " <<ba0<<endl;
    BankAccount ba1("Dave", 1000);
    cout <<"ba1: " <<ba1 << endl;
    BankAccount ba2 ("John", 999);
    cout <<"ba2: " <<ba2 <<endl;
    BankAccount ba3 = ba2;
    cout << "Testing copy constructor ba3 = ba3. ba3: " << ba3 <<endl;
    
    if(ba1!=ba2)
    {
        cout << "Testing ba1!=ba2: accounts are different." << endl;
    }
    if(ba1==ba2)
    {
        cout << "Testing ba1==ba2: accounts are the same" << endl;
    }
    ba1.Deposit(1000);
    cout <<"Testing ba1.Deposit(1000). ba1: " <<ba1 <<endl;
    
    ba1.Withdraw(2000);
    cout <<"Testing ba1.Withdraw(2000). ba1: " <<ba1 <<endl;
    
    cout<<"Testing the input operator >>. Please type a string and a number." << endl;
    BankAccount ba4;
    cin >> ba4;
    cout << ba4 << endl;
    return 0;
}