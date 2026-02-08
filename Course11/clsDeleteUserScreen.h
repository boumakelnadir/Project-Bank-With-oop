#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\n\tUser Card:";
		cout << "\n\t___________________";
		cout << "\n\tUser Name   : " << User.UserName;
		cout << "\n\tFull Name   : " << User.FullName();
		cout << "\n\tPhone       : " << User.PhoneNumber;
		cout << "\n\tEmail       : " << User.Email;
		cout << "\n\tPassword    : " << User.Password;
		cout << "\n\tPermissions : " << User.Permissions;
		cout << "\n\t___________________\n";
	}

public:
	
	static void ShowDeleteUserScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Delete Users Screen");

		string Username;
		cout << "\n\tPlease Enter Username: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\n\tUsername Not Found, Choose Another One : ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_PrintUser(User);

		cout << "\n\n\tAre You Sure Want Delete User [Y/N] : ";

		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\n\tUser Deleted Successfully.\n";

				_PrintUser(User);
			}
			else
			{
				cout << "\n\tUser Delete Failed.\n";
			}
		}

	}
};

