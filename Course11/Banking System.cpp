#include <iostream>
#include "clsLogInScreen.h"
#include "Global.h"

using namespace std;

int main()
{
	while (CounterLoginFailds != 0 )
	{
		clsLogInScreen::ShowLogInScreen();
	}

	//system("pause>0");

	return 0;
}
