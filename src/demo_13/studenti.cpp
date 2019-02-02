// studenti.cpp -- Student class using private inheritance
#include "demo_13/studenti.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods
double Studenti::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum()/ArrayDb::size();	// 私有继承时，使用类名和作用域解析符来调用方法
    else
        return 0;
}

const string & Studenti::Name() const
{
    return (const string &) *this;
}

double & Studenti::operator[](int i)
{
    return ArrayDb::operator[](i);         // use ArrayDb::operator[]()
}

double Studenti::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// private method
ostream & Studenti::arr_out(ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os; 
}

// friends
// use String version of operator>>()
istream & operator>>(istream & is, Studenti & stu)
{
    is >> (string &)stu;
    return is; 
}

// use string friend getline(ostream &, const string &)
istream & getline(istream & is, Studenti & stu)
{
    getline(is, (string &)stu);
    return is;
}

// use string version of operator<<()
ostream & operator<<(ostream & os, const Studenti & stu)
{
    os << "Scores for " << (const string &) stu  << ":\n";
    stu.arr_out(os);  // use private method for scores
    return os;
}
