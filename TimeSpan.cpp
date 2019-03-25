/*
 Chelsea Ip
 Professor Eyal Arian
 CSS 342 
 Program 1: TimeSpan
 This programming assignment will provide exercises in designing classes with proper abstraction and encapsulation.
 Design & implement a TimeSpan class which represents a duration of time in hours, minutes, and seconds. 
 This class implements the addition, subtraction and unary negation, as well as the += and -= assignment
 statements as well. The >> and << operators are also implemented to work on streams.
 */


#include "TimeSpan.h"
#include <cmath>

//destructor: member function which destructs or deletes objects
TimeSpan::~TimeSpan() 
{
    //cout<< "The following object has been destroyed: " <<  *this << endl;
}

//Constructor: The default is (0,0,0)
TimeSpan::TimeSpan() 
{
    this->conversion(0, 0, 0);
}

//Constructor: Receives all three parameters with double as data type, and converts it
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    this->conversion(hours, minutes, seconds);
}

//Constructor: Receives only minutes and seconds as double, and converts it
TimeSpan::TimeSpan(double minutes, double seconds) 
{
    this->conversion(0, minutes, seconds);
}

//Constructor: Receives only seconds as double, and converts it 
TimeSpan::TimeSpan(double seconds)
{
    this->conversion(0, 0, seconds);
}

//This get method return the number of hours as an int
int TimeSpan::getHours() const 
{ 
    return hours;
}
//This get method return the number of minutes as an int
int TimeSpan::getMinutes() const 
{
    return minutes;
}

//This get method return the number of seconds as an int
int TimeSpan::getSeconds() const 
{
    return seconds;
}

//This set method sets the number of hours, minutes and seconds then returns if it's true
bool TimeSpan::setTime(int hours, int minutes, int seconds) 
{
    this-> hours = hours;
    this-> minutes = minutes;
    this-> seconds = seconds;
    return true;
}

//Addition of two times, current object and parameter
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const 
{
    return TimeSpan(this->hours + ts.hours, this->minutes + ts.minutes, this->seconds + ts.seconds);
}

//Subtraction of two times, current object and parameter
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const 
{
    return TimeSpan(this->hours - ts.hours, this->minutes - ts.minutes, this->seconds - ts.seconds);
}

//Negation -
TimeSpan TimeSpan::operator-() const 
{
    return TimeSpan(-(this->hours), -(this->minutes), -(this->seconds));
}

//This object += the parameter
TimeSpan& TimeSpan::operator+=(const TimeSpan &ts) 
{
    this->hours += ts.hours;
    this->minutes += ts.minutes;
    this->seconds += ts.seconds;
    return *this;
}
//This object -= the parameter
TimeSpan& TimeSpan::operator-=(const TimeSpan &ts) 
{
    this->hours -= ts.hours;
    this->minutes -= ts.minutes;
    this->seconds -= ts.seconds;
    return *this;
}

//Returns true if this object == parameter, otherwise false
bool TimeSpan::operator==(const TimeSpan &ts) const 
{

    return (this->hours == ts.hours && this->minutes == ts.minutes && this->seconds == ts.seconds);
}

//Returns true if this object != parameter, otherwise false
bool TimeSpan::operator!=(const TimeSpan &ts) const 
{
    return (this->hours != ts.hours && this->minutes != ts.minutes && this->seconds != ts.seconds);
}

//Prints hours, minutes and seconds respectively
ostream& operator<<(ostream &outStream, const TimeSpan &ts) 
{
    outStream <<"Hours: " << ts.getHours() << ", Minutes: " << ts.getMinutes() << ", Seconds: " << ts.getSeconds() <<endl;
    return outStream;
}

//Prompts user to enter hours, minutes and seconds then calls conversion function
istream& operator>>(istream &in, TimeSpan &ts) 
{
    double hours, minutes, seconds;
    cout << "\nEnter Hours :  ";
    in >> hours;
    cout << "\nEnter Minutes :  ";
    in >> minutes;
    cout << "\nEnter Seconds :  ";
    in >> seconds;
    ts.conversion(hours, minutes, seconds);
    return in;
}

//This function converts it all to seconds before separating it to hours,minutes and seconds respectively
//1 hour = 3600 seconds; one minute = 60 second; seconds rounded to the nearest integer.
void TimeSpan::conversion(double hours, double minutes, double seconds) 
{
    int hoursToSeconds = hours * 60 * 60;
    int minutesToSeconds = minutes * 60;
    int totalSeconds = seconds + hoursToSeconds + minutesToSeconds;

    hours = totalSeconds / 3600;
    totalSeconds = totalSeconds % 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    seconds = round(seconds);

    this->minutes = minutes;
    this->hours = hours;
    this->seconds = seconds;
}