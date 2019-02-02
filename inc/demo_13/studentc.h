// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>   
#include <valarray>

class Student
{   
private:
    typedef std::valarray<double> ArrayDb;			// 简化类型，便于书写

    std::string name;       // contained object
    ArrayDb scores;         // contained object

    // private method for scores output
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : name("Null Student"), scores() {}	// 默认构造函数
    explicit Student(const std::string & s)			// 一个参数为字符串类的构造函数，禁止隐式转换调用此构造函数
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}		// 一个参数为int值的构造函数，禁止隐式转换调用此构造函数
    Student(const std::string & s, int n)						// 两个参数分别为string&,int的构造函数
        : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)			// 两个参数分别为string&,ArrayDb&的构造函数
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)			// 三个参数分别为char *,double *,int的构造函数
        : name(str), scores(pd, n) {}
    ~Student() {}									// 默认析构函数

    double Average() const;							// 计算ArrayDb中的平均分数
    const std::string & Name() const;				// 得到学生姓名的引用
    double & operator[](int i);						// 得到第i个的分数引用
    double operator[](int i) const;					// 得到第i个的分数

// friends
    // input (允许操作Student类的私有成员和私有方法)
    friend std::istream & operator>>(std::istream & is,
                                     Student & stu);  // 1 word
    friend std::istream & getline(std::istream & is,
                                  Student & stu);     // 1 line
    // output ()
    friend std::ostream & operator<<(std::ostream & os,
                                     const Student & stu);
};

#endif
