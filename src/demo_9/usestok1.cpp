// usestok1.cpp -- using the Stock class
// compile with stock10.cpp
#include <iostream>
#include "demo_9/stock10.h"

int use_stock10_test()
{
  {
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock10 stock1("NanoSmart", 12, 20.0);				// (��ʽ���ù��캯��)
    stock1.show();
    Stock10 stock2 = Stock10 ("Boffo Objects", 2, 2.0);	// (��ʽ���ù��캯��)
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
	// ��һ������ֵ��ͬ���͵���һ������ʱ���Ѷ����ÿ�����ݳ�Ա�����ݸ��Ƶ�Ŀ������ж�Ӧ�����ݳ�Ա��
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
	// �������Ѿ����ڣ����캯����������ʱ����Ȼ�������ݸ��Ƹ�ԭ�����ڵĶ���
    stock1 = Stock10("Nifty Foods", 10, 50.0);    // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";
  }
	// std::cin.get();
    return 0; 
}
