#pragma once

#include <iostream>
#include "clsScreenHeader.h"
#include"clsUsers.h"


class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintRegisterUsersRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{

		cout << "| " << left << setw(40) << LoginRegisterRecord.DateTime;
		cout << "| " << left << setw(20) << LoginRegisterRecord.UserName;
		cout << "| " << left << setw(20) << LoginRegisterRecord.Password;
		cout << "| " << left << setw(15) << LoginRegisterRecord.Permissions;
	}



public:

	static void ShowLoginRegisterScreen()
	{

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pLogInRegister))
		{
			return;
		}
		
		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterRecordsList();

		string Title = "\t\t  Login Register Screen";
		string SubTitle = "\t\t   (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		clsScreen::DrawTitleHeader(Title, SubTitle);

		cout << "\n\n\t|------------------------------------------------------------------------------------------------------------|\n";
		cout << "\t| " << left << setw(40) << "Date Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout << "\n\t|------------------------------------------------------------------------------------------------------------|\n";

		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\n\t\t\tNo Records Available In The System.\n";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				cout << "\t";

				_PrintRegisterUsersRecordLine(Record);
				cout << endl;
			}
			cout << "\t|------------------------------------------------------------------------------------------------------------|\n";

		}
	}


};

