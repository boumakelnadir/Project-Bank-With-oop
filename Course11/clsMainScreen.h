#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreenHeader.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenu.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"


using namespace std;


class clsMainScreen : protected clsScreen
{
private:
	enum _enMainMenuOptions
	{
		eShowClientsList = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClientInfo = 4,
		eFindClient = 5,
		eTransactions = 6,
		eManageUsers = 7,
		eLogInRegister = 8,
		eLogout = 9
	};

	static void _ShowClientsListScreen() 
	{
		clsClientListScreen::ShowClientList();
	};
	
	static void _ShowAddNewClientScreen() 
	{
		clsAddNewClientScreen::ShowAddNewClient();
	};
	
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	};
	
	static void _ShowUpdateClientScreen() 
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	};
	
	static void _ShowFindClientScreen() 
	{
		clsFindClientScreen::ShowFindClientScreen();
	};
	
	static void _ShowTransactionsScreen() 
	{
		clsTransactionMenu::ShowTransactionMenueScreen();
	};
	
	static void _ShowManageUsersScreen() 
	{
		clsManageUsersScreen::ShowManageUsersScreen();
	};
	
	static void _ShowLogInRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	};

	static void _ShowLogOutScreen()
	{
		CurrentUser = clsUser::Find("", "");
	};

	static void _GoBackToMainMenue()
	{
		cout << "\n\tPress Any Key To Go Back Main Menu..." ;
		system("pause>0");
		_ClearScreen();
		ShowMainMenue();
	};

	static void _ClearScreen()
	{
		system("cls");
	}

	static int _ReadMainMenuOption()
	{
		int Choice  ;
		cout << "\n\t\t\t\t\tPlease choose what do you want to do? (1-9): ";
		Choice = clsInputValidate::ReadIntNumberBetween(1, 9, "\nNumber is Not a Range [1-9] , Choose Again :");
		return Choice;
	}

	static void _PerformMainMenueOption(_enMainMenuOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
			case eShowClientsList:
			{
				_ClearScreen();
				_ShowClientsListScreen();
				_GoBackToMainMenue();
				break;
			}
			case eAddNewClient:
			{
				_ClearScreen();
				_ShowAddNewClientScreen();
				_GoBackToMainMenue();
				break;
			}
			case eDeleteClient:
			{
				_ClearScreen();
				_ShowDeleteClientScreen();
				_GoBackToMainMenue();
				break;
			}
			case eUpdateClientInfo:
			{
				_ClearScreen();
				_ShowUpdateClientScreen();
				_GoBackToMainMenue();
				break;
			}
			case eFindClient:
			{
				_ClearScreen();
				_ShowFindClientScreen();
				_GoBackToMainMenue();
				break;
			}
			case eTransactions:
			{
				_ClearScreen();
				_ShowTransactionsScreen();
				_GoBackToMainMenue();
				break;
			}
			case eManageUsers:
			{
				_ClearScreen();
				_ShowManageUsersScreen();
				_GoBackToMainMenue();
				break;
			}
			case eLogInRegister:
			{
				_ClearScreen();
				_ShowLogInRegisterScreen();
				_GoBackToMainMenue();
				break;
			}
			case eLogout:
			{
				_ClearScreen();
				_ShowLogOutScreen();
				break;
			}
		}
	}

public:

	static void ShowMainMenue()
	{
		_ClearScreen();

		clsScreen::DrawTitleHeader("\t\tMain Menue Screen");

		cout << "\t\t\t\t\t[1]. Show Client List.\n";
		cout << "\t\t\t\t\t[2]. Add New Client.\n";
		cout << "\t\t\t\t\t[3]. Delete Client.\n";
		cout << "\t\t\t\t\t[4]. Update Client Info.\n";
		cout << "\t\t\t\t\t[5]. Find Client.\n";
		cout << "\t\t\t\t\t[6]. Transactions.\n";
		cout << "\t\t\t\t\t[7]. Manage Users.\n";
		cout << "\t\t\t\t\t[8]. LogIn Register.\n";
		cout << "\t\t\t\t\t[9]. Logout.\n";
		cout << "\t\t\t\t\t=====================================\n";

		_PerformMainMenueOption((_enMainMenuOptions)_ReadMainMenuOption());
	}

};

