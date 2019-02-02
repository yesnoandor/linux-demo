// usett0.cpp -- using a base class
#include <iostream>
#include "demo_12/tabtenn0.h"

int usett0_test ( void )
{
	using std::cout;
	using std::endl;
	
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	player2.Name();
	if (player2.HasTable())
		cout << ": has a table";
	else
		cout << ": hasn't a table.\n";

    rplayer1.Name();          // derived object uses base method
    if (rplayer1.HasTable())
    	cout << ": has a table.\n";
    else
    	cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

	// initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
    
    // std::cin.get();

    return 0;
}
