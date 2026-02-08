#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser& User)
	{
		cout << "\n\tUser Card:";
		cout << "\n\t___________________";
		cout << "\n\tFirstName   : " << User.FirstName;
		cout << "\n\tLastName    : " << User.LastName;
		cout << "\n\tFull Name   : " << User.FullName();
		cout << "\n\tEmail       : " << User.Email;
		cout << "\n\tPhone       : " << User.PhoneNumber;
		cout << "\n\tUser Name   : " << User.UserName;
		cout << "\n\tPassword    : " << User.Password;
		cout << "\n\tPermissions : " << User.Permissions;
		cout << "\n\t___________________\n";

	}

public:

	static void ShowFindUserScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Find User Screen");

		string UserName;
		cout << "\n\tPlease Enter Username : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n\tUser Not Found, Enter Choose Another One"
				<< UserName << " is not exist, Enter another Username : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (User.IsEmpty())
		{
			cout << "\n\tUser Not Found In The System.\n";
			return;
		}

		_PrintUser(User);
	}

};
