#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsUsers.h"
#include "Global.h"
#include"clsDate.h"

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

		if (CurrentUser.IsEmpty())
		{
			cout << "\n\t\t\t\t\tUser : " ;
		}
		else
			cout << "\n\t\t\t\t\tUser : " <<  CurrentUser.UserName;

		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;
		cout << "\n\t\t\t\t\t=====================================\n\n";

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

