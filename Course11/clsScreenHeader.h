#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsUsers.h"
#include "Global.h"


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

	static bool CheckAccessRights(int RequiredPermissions)
	{
		if ((CurrentUser.Permissions & RequiredPermissions) == RequiredPermissions)
		{
			return true;
		}
		else
		{
			DrawTitleHeader("\t\t     Access Denied Screen");

			cout << "\n\tSorry, You don't have the required permissions to access this screen.\n";
			return false;
		}
	}

};

