// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>   
#include <valarray>

class Student
{   
private:
    typedef std::valarray<double> ArrayDb;			// �����ͣ�������д

    std::string name;       // contained object
    ArrayDb scores;         // contained object

    // private method for scores output
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : name("Null Student"), scores() {}	// Ĭ�Ϲ��캯��
    explicit Student(const std::string & s)			// һ������Ϊ�ַ�����Ĺ��캯������ֹ��ʽת�����ô˹��캯��
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}		// һ������Ϊintֵ�Ĺ��캯������ֹ��ʽת�����ô˹��캯��
    Student(const std::string & s, int n)						// ���������ֱ�Ϊstring&,int�Ĺ��캯��
        : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)			// ���������ֱ�Ϊstring&,ArrayDb&�Ĺ��캯��
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)			// ���������ֱ�Ϊchar *,double *,int�Ĺ��캯��
        : name(str), scores(pd, n) {}
    ~Student() {}									// Ĭ����������

    double Average() const;							// ����ArrayDb�е�ƽ������
    const std::string & Name() const;				// �õ�ѧ������������
    double & operator[](int i);						// �õ���i���ķ�������
    double operator[](int i) const;					// �õ���i���ķ���

// friends
    // input (�������Student���˽�г�Ա��˽�з���)
    friend std::istream & operator>>(std::istream & is,
                                     Student & stu);  // 1 word
    friend std::istream & getline(std::istream & is,
                                  Student & stu);     // 1 line
    // output ()
    friend std::ostream & operator<<(std::ostream & os,
                                     const Student & stu);
};

#endif
