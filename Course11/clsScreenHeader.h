#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsScreen
{
public:

	static void DrawTitleHeader(string Title , string SubTitle = "")
	{
		cout << "\t\t\t\t\t=====================================";
		cout << "\n\t\t\t\t" << Title << "\n";
		
		if (SubTitle != "")
			cout << "\t\t\t\t" << SubTitle << "\n";

		cout << "\t\t\t\t\t=====================================\n";
	}
};

