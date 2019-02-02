// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time03
{
private:
    int hours;
    int minutes;
public:
    Time03();
    Time03(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time03 operator+(const Time03 & t) const;
    Time03 operator-(const Time03 & t) const;
    Time03 operator*(double n) const;
	// 友元内联函数
    friend Time03 operator*(double m, const Time03 & t)
        { return t * m; }   // inline definition
	// 友元函数
    friend std::ostream & operator<<(std::ostream & os, const Time03 & t);

};
#endif
