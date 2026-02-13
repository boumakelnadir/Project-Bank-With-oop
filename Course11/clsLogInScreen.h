#pragma once
#include <iostream>
#include"clsUsers.h"
#include"clsScreenHeader.h"
#include"clsInputValidate.h"
#include "clsMainScreen.h"
#include"Global.h"



using namespace std;



class clsLogInScreen : protected clsScreen
{
private:

	static void _LogIn()
	{
		string UserName, Password;

		bool LoginFailed = false;
		

		do
		{
			
			if (LoginFailed)
			{
				CounterLoginFailds--;
				cout << "\n\tInvalid UserName or Password, Please try again.\n";
				cout << "\tYou have " << CounterLoginFailds << " Trials to Login" << endl;
				
			}

			if (CounterLoginFailds == 0)
			{
				cout << "\n\tYou are Locked After 3 Faild Trails" << endl;
				return;
			}

			cout << "\n\tPlease enter UserName: ";
			UserName = clsInputValidate::ReadString();

			cout << "\n\tPlease enter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();


		} while (LoginFailed);
		
		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
	}

public:

	static void ShowLogInScreen()
	{
		system("cls");
		clsScreen::DrawTitleHeader("\t\t     Login Screen");
		_LogIn();
	}

};

