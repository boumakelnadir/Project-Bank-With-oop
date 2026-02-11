#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;


class clsManageUsersScreen : protected clsScreen
{
private:

	enum _enManageUsersMenuOptions
	{
		eShowUsersList = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUserInfo = 4,
		eFindUser = 5,
		eBackToMainMenue = 6,
	};

	static void _ShowUsersListScreen()
	{
		clsUserListScreen::ShowUsersListScreen();
	};

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	};

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	};

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	};

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	};

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\tPress Any Key To Go Back Manage Users Menu...";
		system("pause>0");
		_ClearScreen();
		ShowManageUsersScreen();
	};

	static void _ClearScreen()
	{
		system("cls");
	}

	static int _ReadManageUsersOption()
	{
		int Choice;
		cout << "\n\t\t\t\t\tPlease choose what do you want to do? (1-6): ";
		Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "\nNumber is Not a Range [1-5] , Choose Again :");
		return Choice;
	}

	static void _PerformManageUsersMenuOption(_enManageUsersMenuOptions ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
			case eShowUsersList:
			{
				_ClearScreen();
				_ShowUsersListScreen();
				_GoBackToManageUsersMenue();
				break;
			}

			case eAddNewUser:
			{
				_ClearScreen();
				_ShowAddNewUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}

			case eDeleteUser:
			{
				_ClearScreen();
				_ShowDeleteUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}

			case eUpdateUserInfo:
			{
				_ClearScreen();
				_ShowUpdateUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}

			case eFindUser:
			{
				_ClearScreen();
				_ShowFindUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}

			case eBackToMainMenue:
			{
				break;
			}
		}
	}

public:
	
	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		clsScreen::DrawTitleHeader("\t\tManage Users Screen");

		cout << "\n\n\t\t\t\t\t=====================================";
		cout << "\n\t\t\t\t" << "\t\tManage User Menue" << "\n";
		cout << "\t\t\t\t\t=====================================\n";
		cout << "\t\t\t\t\t[1]. List Users.\n";
		cout << "\t\t\t\t\t[2]. Add New Users.\n";
		cout << "\t\t\t\t\t[3]. Delete Users.\n";
		cout << "\t\t\t\t\t[4]. Update Users Info.\n";
		cout << "\t\t\t\t\t[5]. Find Users.\n";
		cout << "\t\t\t\t\t[6]. Back To Main Menue.\n";
		cout << "\t\t\t\t\t=====================================\n";

		_PerformManageUsersMenuOption((_enManageUsersMenuOptions)_ReadManageUsersOption());
	}

};

