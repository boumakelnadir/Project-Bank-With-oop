#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		char Answer = 'N';

		cout << "\n\n\tDo You Want Update First Name [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter First Name : ";
			Client.FirstName = clsInputValidate::ReadString();
		}
		
		cout << "\n\n\tDo You Want Update Last Name [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter Last Name : ";
			Client.LastName = clsInputValidate::ReadString();
		}
		
		cout << "\n\n\tDo You Want Update Email [Y/N] ? ";
		cin >> Answer;
		
		if(toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter Email : ";
			Client.Email = clsInputValidate::ReadString();
		}
		
		cout << "\n\n\tDo You Want Update Phone Number [Y/N] ? ";
		cin >> Answer;
		
		if (toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter Phone Number : ";
			Client.PhoneNumber = clsInputValidate::ReadString();
		}
		
		cout << "\n\n\tDo You Want Update Pin Code [Y/N] ? ";
		cin >> Answer;
		
		if (toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter PinCode : ";
			Client.PinCode = clsInputValidate::ReadString();
		}
		
		cout << "\n\n\tDo You Want Update Account Balance [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\tPlease Enter Account Balance : ";
			Client.AccountBalance = clsInputValidate::ReadDblNumber();
		}
	}

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
		cout << "\n\t------------------------------";
	}

public:

	static void ShowUpdateClientScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Update Client Screen");

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
		_PrintClientCard(Client);

		cout << "\n\n\tDo You Want Update This Client [Y/N] ? ";
		char Answer = 'N';
		cin >> Answer;
		
		if (toupper(Answer) != 'Y')
			return;

		cout << "\n\n\tUpdate Client Info:\n" << endl;

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n\tClient Updated Successfully.\n";
			_PrintClientCard(Client);
			break;
		}

		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\n\tClient Update Failed Because Client is Empty.\n";
			break;
		}
		}
	}

};

