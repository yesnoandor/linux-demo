// mytime3.cpp  -- implementing Time methods
#include "demo_10/mytime3.h"

Time03::Time03()
{
    hours = minutes = 0;
}

Time03::Time03(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time03::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time03::AddHr(int h)
{
    hours += h;
}

void Time03::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time03 Time03::operator+(const Time03 & t) const
{
    Time03 sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time03 Time03::operator-(const Time03 & t) const
{
    Time03 diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time03 Time03::operator*(double mult) const
{
    Time03 result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time03 & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os; 
}
