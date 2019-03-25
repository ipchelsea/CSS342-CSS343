
#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main() {
    TimeSpan t1(1, 5, 2), t2(5, 4, 3), t3, t4(2.4,3,2), t5;
    
    //testing input operator
    cout << "Entering time for t3 = " <<endl;
    cin >> t3; 
    
    //testing output operator
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
    cout << "t3 = " << t3 << endl; //input time
    cout << "t4 = " << t4 << endl;
    cout << "(t5 = 0) = " << (t5 = 0) << endl;
    
    //testing unary negation method
    cout << "-t1 = " << -t1 << endl;
    cout << "-t2 = " << -t2 << endl;
    
    //testing set time method
    t4.setTime(1,5,2);
    cout << "After re-setting to new time, t4 is = " << t4 << endl;
    
    //testing arithmetic operators
    cout << "(t1 + t2) = " << (t1 + t2) << endl;
    cout << "(t1 - t2) = " << (t1 - t2) << endl;
    cout << "(t1 + t2 + t3) = " << t1 + t2 + t3 << endl;
    cout << "(t1 - t2 - t3) = " << t1 - t2 - t3 << endl;
    
    //testing boolean operators
     if(t1!=t2)
    {
        cout << "Testing t1!=t2: both times are different." << endl;
    }
    if(t1==t2)
    {
        cout << "Testing t1==t2: both times are the same" << endl;
    }
   
    //testing assignment operators
    cout << "((t1 += t2) += t3) = " << ((t1 += t2) += t3 ) << endl;
    cout << "((t5 += t4) += t2) = " << ((t5 += t4) += t2 ) << endl;
    cout << "(t1 -= t2) = " << (t1 -= t2) << endl;

    return 0;
}