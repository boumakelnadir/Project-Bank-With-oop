#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\t------------------------------";
		cout << "\n\t\tCard Client";
		cout << "\n\t------------------------------";
		cout << "\n\tFirst Name     = " << Client.FirstName;
		cout << "\n\tLast Name      = " << Client.LastName;
		cout << "\n\tFull Name      = " << Client.FullName();
		cout << "\n\tEmail          = " << Client.Email;
		cout << "\n\tPhoneNumber    = " << Client.PhoneNumber;
		cout << "\n\tAccountNumber  = " << Client.GetAccountNumber();
		cout << "\n\tPinCode        = " << Client.PinCode;
		cout << "\n\tAccountBalance = " << Client.AccountBalance;
		cout << "\n\t------------------------------";
	}

public:

	static void ShowFindClientScreen()
	{

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		clsScreen::DrawTitleHeader("\t\t  Find Client Screen");

		string AccountNumber;
		cout << "\n\tPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\tClient with Account Number Not Found, Enter Choose Another One"
				<< AccountNumber << " is not exist, Enter another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (Client.IsEmpty())
		{
			cout << "\n\tClient Not Found In The System.\n";
			return;
		}

		_PrintClientCard(Client);
	}

};

