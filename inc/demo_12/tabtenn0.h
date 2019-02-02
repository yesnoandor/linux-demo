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
// 1. �����಻�ܷ��ʻ����˽�г�Ա������ͨ�����෽�����з���
// 2. ����ָ������ڲ�������ʽת���������ָ�����������
// 3. �������ÿ����ڲ�������ʽת����������������������
class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;

public:
	// ������Ĺ��캯��
	//	1. �����������
	//	2. �����๹�캯��Ӧͨ����Ա��ʼ���б�������Ϣ���ݸ����๹�캯��
	//	3. �����๹�캯��Ӧ��ʼ�����������������ݳ�Ա
    RatedPlayer (unsigned int r = 0, const string & fn = "none",
                 const string & ln = "none", bool ht = false);

    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);

    unsigned int Rating() const { return rating; }

    void ResetRating (unsigned int r) {rating = r;}

};



#endif
