// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;

// simple base class
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer (const string & fn = "none",
                       const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};

// simple derived class
// 1. 派生类不能访问基类的私有成员，必须通过基类方法进行访问
// 2. 基类指针可以在不进行显式转换的情况下指向派生类对象
// 3. 基类引用可以在不进行显式转换的情况下引用派生类对象
class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;

public:
	// 派生类的构造函数
	//	1. 创建基类对象
	//	2. 派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数
	//	3. 派生类构造函数应初始化派生类新增的数据成员
    RatedPlayer (unsigned int r = 0, const string & fn = "none",
                 const string & ln = "none", bool ht = false);

    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);

    unsigned int Rating() const { return rating; }

    void ResetRating (unsigned int r) {rating = r;}

};



#endif
