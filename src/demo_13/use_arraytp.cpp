
#include <iostream>
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()

#include "demo_13/arraytp.h"

int use_arraytp_test()
{
    const int size = 5;
    ArrayTP<double, size> eggweights;

    std::srand(std::time(0)); // randomize rand()

    for(int i=0;i<size;i++)
    {
    	double d=((double)std::rand())/RAND_MAX;
    	eggweights[i] = 2.0 * i + d;

    	std::cout << d << std::endl;
	}

	std::cout << "----------" << std::endl;
	for (int i = 0; i < size; i++)
        std::cout << eggweights[i] << std::endl;

	
    std::cout << "Bye\n";
	return 0;
}
