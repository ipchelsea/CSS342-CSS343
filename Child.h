#include <iostream>
#include <string>
#ifndef CHILD_H
#define CHILD_H


using namespace std;


class Child 
{
    friend ostream& operator<<(ostream &outStream, const Child&Source);
    
public:
    
    Child();
    Child(string last);
    Child(string first, string last);
    Child(string first, string last, int age);
    ~Child();
    
    //boolean operators
    bool operator>(const Child &source) const;
    bool operator<(const Child &source) const;
    bool operator==(const Child &source) const;
    bool operator!=(const Child &source) const;
    void operator=(const Child &source); //=operator
    
    //setter methods
    void setFirst(const string first);
    void setLast(string last);
    void setName(const string first, const string last);
    void setAge(int age);
    
    //getter methods
    string getFirst() const;
    string getlast() const;
    int getAge()const;
    
private:
    string firstName;
    string lastName;
    int age;
};

#endif 

