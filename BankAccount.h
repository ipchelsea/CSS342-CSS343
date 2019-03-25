/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BankAccount.h
 * Author: chelseaiptzehwan
 *
 * Created on 14 January 2019, 21:23
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <cmath>
using namespace std;

class BankAccount {
    friend ostream& operator<<(ostream& outStream, const BankAccount& bank);
    friend istream& operator>>(istream &inStream, BankAccount &bank);

public:

    BankAccount();
    BankAccount(string name);
    BankAccount(string name, double amount);
    ~BankAccount();

    string getName() const;
    double getBalance() const;
    bool setName(string name);

    void Deposit(const double amount);
    void Withdraw(const double amount);

    bool operator==(const BankAccount& bank)const;
    bool operator!=(const BankAccount& bank) const;




private:
    string name;
    double balance;
};

#endif /* BANKACCOUNT_H */

