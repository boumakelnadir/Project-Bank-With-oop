#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawMoneyScreen.h"
#include "clsTotalBalancesScreen.h"


using namespace std;


class clsTransactionMenu : protected clsScreen
{
private:

	enum enTransactionMenuOptions
	{
		eDepositMoney = 1,
		eWithdrawMoney = 2,
		eTotalBalancesMoney = 3,
		eBackToMainMenu = 4
	};

	static void _GoBackToMainMenue()
	{
		cout << "\n\tPress Any Key To Go Back Main Menu...";
		system("pause>0");
		_ClearScreen();
		//clsMainScreen::ShowMainMenue();
	};

	static void _GoBackToTransactionMenue()
	{
		cout << "\n\tPress Any Key To Go Back Transaction Menu...";
		system("pause>0");
		_ClearScreen();
		ShowTransactionMenueScreen();
	};

	static void _ClearScreen()
	{
		system("cls");
	}

	static void _ShowDepositMoneyScreen() 
	{
		clsDepositScreen::ShowDepositScreen();
	};
	
	static void _ShowWithdrawMoneyScreen() 
	{
		clsWithdrawMoneyScreen::ShowWithdrawScreen();
	};
	
	static void _ShowTotalBalancesMoneyScreen() 
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	};
	
	static int _ReadTransactionMenuOption()
	{
		int Choice;
		cout << "\n\t\t\t\t\tPlease choose what do you want to do? (1-4): ";
		Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "\nNumber is Not a Range [1-8] , Choose Again :");
		return Choice;
	}

	static void _PerformTransactionMenueOption(enTransactionMenuOptions TranMenuOpt)
	{
		switch (TranMenuOpt)
		{
			case eDepositMoney:
			{
				_ClearScreen();
				_ShowDepositMoneyScreen();
				_GoBackToTransactionMenue();
				break;
			}

			case eWithdrawMoney:
			{
				_ClearScreen();
				_ShowWithdrawMoneyScreen();
				_GoBackToTransactionMenue();
				break;
			}

			case eTotalBalancesMoney:
			{
				_ClearScreen();
				_ShowTotalBalancesMoneyScreen();
				_GoBackToTransactionMenue();
				break;
			}

			case eBackToMainMenu:
			{
				_ClearScreen();
				break;
			}

		}
	}

public:

	static void ShowTransactionMenueScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		clsScreen::DrawTitleHeader("\t\tTransactions Screen");

		cout << "\n\n\t\t\t\t\t=====================================";
		cout << "\n\t\t\t\t" << "\t\tTransactions Menue" << "\n";
		cout << "\t\t\t\t\t=====================================\n";
		cout << "\t\t\t\t\t[1]. Deposit Money.\n";
		cout << "\t\t\t\t\t[2]. Withdraw Money.\n";
		cout << "\t\t\t\t\t[3]. Total Balances Money.\n";
		cout << "\t\t\t\t\t[4]. Back To Main Menu.\n";
		cout << "\t\t\t\t\t=====================================\n";
		
		_PerformTransactionMenueOption((enTransactionMenuOptions)_ReadTransactionMenuOption());
	};

};

