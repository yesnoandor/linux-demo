// studenti.h -- defining a Student class using private inheritance
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <valarray>
#include <string>

// 私有继承：基类的公有成员和保护成员都成为派生类的私有成员
class Studenti : private std::string, private std::valarray<double>
{   
private:
    typedef std::valarray<double> ArrayDb;		// 简化类型，便于书写
	
    // private method for scores output
    std::ostream & arr_out(std::ostream & os) const;
public:
	// 默认构造函数
    Studenti() : std::string("Null Student"), ArrayDb() {}
	
	// 一个参数为字符串类的构造函数，禁止隐式转换调用此构造函数(explicit)
    explicit Studenti(const std::string & s)
            : std::string(s), ArrayDb() {}		// 使用类名而不是成员名来标识构造函数

	// 一个参数为int   值的构造函数，禁止隐式转换调用此构造函数(explicit)
	explicit Studenti(int n) : std::string("Nully"), ArrayDb(n) {}

	
    Studenti(const std::string & s, int n)
            : std::string(s), ArrayDb(n) {}
    Studenti(const std::string & s, const ArrayDb & a)
            : std::string(s), ArrayDb(a) {}
    Studenti(const char * str, const double * pd, int n)
            : std::string(str), ArrayDb(pd, n) {}
    ~Studenti() {}
	
    double Average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const std::string & Name() const;
// friends
    // input
    friend std::istream & operator>>(std::istream & is,
                                     Studenti & stu);  // 1 word
    friend std::istream & getline(std::istream & is,
                                  Studenti & stu);     // 1 line
    // output
    friend std::ostream & operator<<(std::ostream & os,
                                     const Studenti & stu);
};

#endif
