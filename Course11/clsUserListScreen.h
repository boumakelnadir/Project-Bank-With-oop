#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreenHeader.h"
#include "clsUsers.h"



using namespace std;


class clsUserListScreen : protected clsScreen
{
private:

	static void _PrintUsersRecordLine(clsUser U)
	{
		
		cout << "| " << left << setw(25) << U.FullName();
		cout << "| " << left << setw(15) << U.PhoneNumber;
		cout << "| " << left << setw(20) << U.Email;
		cout << "| " << left << setw(20) << U.Password;
		cout << "| " << left << setw(15) << U.Permissions;
	}



public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t\t  Users List Screen";
		string SubTitle = "\t\t   (" + to_string(vUsers.size()) + ") Users(s).";

		clsScreen::DrawTitleHeader(Title, SubTitle);

		cout << "\n\n\t|------------------------------------------------------------------------------------------------------------|\n";

		
		cout << "\t| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout << "\n\t|------------------------------------------------------------------------------------------------------------|\n";

		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\tNo Users Available In The System.\n";
		}
		else
		{
			for (clsUser& U : vUsers)
			{
				cout << "\t";

				_PrintUsersRecordLine(U);
				cout << endl;
			}
			cout << "\t|------------------------------------------------------------------------------------------------------------|\n";

		}
	}



};

