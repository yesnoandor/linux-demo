// usestok2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "demo_9/stock20.h"

const int STKS = 4;

int use_stock20_test()
{{	
// create an array of initialized objects
	// ��ʼ����������ķ����� 
	//		1. ��Ĭ�ϵĹ��캯����������Ԫ��
	//		2. �������еĹ��캯����������ʱ����
	//		3. ����ʱ��������ݸ��Ƶ���Ӧ��Ԫ����
    Stock20 stocks[STKS] = {
        Stock20("NanoSmart", 12, 20.0),
        Stock20("Boffo Objects", 200, 2.0),
        Stock20("Monolithic Obelisks", 130, 3.25),
        Stock20("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();
// set pointer to first element
    const Stock20 * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
	top->show();}
	
    // std::cin.get();
    return 0; 
}
