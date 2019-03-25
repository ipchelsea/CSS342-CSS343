
/* 
 * File:   TimeSpan.h
 * Author: chelseaiptzehwan
 *
 * Created on 11 January 2019, 11:16
 */

//A TimeSpan class
#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <iostream>
using namespace std;

class TimeSpan {
    friend ostream& operator<<(ostream &outStream, const TimeSpan &ts);
    friend istream& operator>>(istream &inStream, TimeSpan &ts);

public:
    ~TimeSpan();
    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);
    
    //Get Methods
    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;
    //Set the number of hours, minutes, seconds and return true if successful
    bool setTime(int hours, int minutes, int seconds);

    //Arithmetic operators
    TimeSpan operator+(const TimeSpan &ts)const;

    TimeSpan operator-(const TimeSpan &ts) const;
    //Unary minus operator
    TimeSpan operator-() const;

    //Boolean comparison operators
    bool operator==(const TimeSpan &ts) const;
    bool operator!=(const TimeSpan &ts) const;

    //Augmented operators
    TimeSpan& operator+=(const TimeSpan &ts);
    TimeSpan& operator-=(const TimeSpan &ts);
    

private:
    int hours;
    int minutes;
    int seconds;
    void conversion(double hours, double minutes, double seconds);
   
};


#endif /* TIMESPAN_H */

