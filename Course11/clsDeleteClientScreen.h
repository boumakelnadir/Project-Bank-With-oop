#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\t------------------------------";
		cout << "\n\t\tCard Client" ;
		cout << "\n\t------------------------------";
		cout << "\n\tFirst Name     = " << Client.FirstName;
		cout << "\n\tLast Name      = " << Client.LastName;
		cout << "\n\tEmail          = " << Client.Email;
		cout << "\n\tPhoneNumber    = " << Client.PhoneNumber;
		cout << "\n\tAccountNumber  = " << Client.GetAccountNumber();
		cout << "\n\tPinCode        = " << Client.PinCode;
		cout << "\n\tAccountBalance = " << Client.AccountBalance;
		cout << "\n\t------------------------------\n";
	}

public:

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		clsScreen::DrawTitleHeader("\t\t  Delete Client Screen");

		string AccountNumber;
		cout << "\n\tPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\tClient with Account Number Not Found, Choose Another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);

		cout << "\n\n\tAre You Sure Want Delete Client [Y/N] : " ;

		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\n\tClient Deleted Successfully.\n";

				_PrintClientCard(Client);
			}
			else
			{
				cout << "\n\tClient Delete Failed.\n";
			}
		}

		

	}

};

