// brass.h  -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_

#include <string>

// Brass Account Class ( 表示基本支票账户)
class Brass	
{
private:
    std::string fullName;	// 客户姓名
    long acctNum;			// 帐号
    double balance;			// 当前结余
public:
    Brass(const std::string & s = "Nullbody", long an = -1,
                double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

//Brass Plus Account Class ( 增加了透支属性的支票账户)
class BrassPlus : public Brass
{
private:
    double maxLoan;		// 透支上限
    double rate;		// 透支贷款利率
    double owesBank;	// 透支总额
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0, double ml = 500,
            double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, 
		                        double r = 0.11125);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; };
    void ResetOwes() { owesBank = 0; }
};

#endif
