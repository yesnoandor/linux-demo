// usenmsp.cpp -- using namespaces
#include <iostream>
#include "demo_8/namesp.h"

void other(void);
void another(void);

int usenmsp_test(void)
{
    using debts::Debt;				// using ����
	using debts::showDebt;
    Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
    showDebt(golf);
    other();
    another(); 
	// std::cin.get();
	// std::cin.get();
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;			// using ����ָ���
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    
    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);

    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    
    return;
}

void another(void)
{
    using pers::Person;;
    
    Person collector = { "Milo", "Rightshift" };
    pers::showPerson(collector);
    std::cout << std::endl; 
}
