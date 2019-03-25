#include "BankAccount.h"
//
// Constructors
BankAccount::BankAccount()
{
  this->name = "NULL";
  this->balance = 0;
  //cout << "A new account has been opened." << endl;
}

BankAccount::BankAccount(string nam)
{
  this->name = nam;
  this->balance = 0;
  //cout << "A new account has been opened for " << name <<". ";
}

BankAccount::BankAccount(string nam, double bal)
{
  this->name = nam;
  this->balance = bal;
  //cout << "A new account has been opened for " << name <<". ";
  //cout <<  "$" << balance << " has been deposited." << endl;
}

BankAccount::~BankAccount()
{
  //cout<< "The following object has been destroyed: " <<  *this << endl;
}

//
//getters and setters
double BankAccount::getBalance() const
{
  return balance;
}
string BankAccount::getName() const
{
  return name;
}
bool BankAccount::setName(string nam)
{
  this->name = nam;
  return true;
}
//
//deposit and withdraw methods
void BankAccount::Deposit(const double amount)
{
  balance += amount;
}

void BankAccount::Withdraw(const double amount)
{
  if (balance>=amount)
  {
    balance -= amount;
  }
  else
  {
    cout << "Deposit denied. Not enough funds in the account." << endl;
  }
}
//
// operator overload

bool BankAccount::operator==(const BankAccount &bank) const
{
  return (this->name == bank.name && this->balance == bank.balance);
}

bool BankAccount::operator!=(const BankAccount &bank) const
{
  return (this->name != bank.name || this->balance == bank.balance);
}
//
// Implementation of friend io methods
ostream& operator <<(ostream &outStream, const BankAccount &bank)
{
  outStream << "Account name: " << bank.name <<", Account balance: $" << bank.balance;
  return outStream;
}

istream& operator >>(istream &inStream, BankAccount &bank)
{
  inStream >> bank.name >> bank.balance;
  return inStream;
}
