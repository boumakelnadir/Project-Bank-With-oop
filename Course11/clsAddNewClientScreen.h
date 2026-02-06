#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\tPlease Enter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\tPlease Enter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\tPlease Enter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\tPlease Enter Phone Number : ";
		Client.PhoneNumber = clsInputValidate::ReadString();

		cout << "\tPlease Enter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\tPlease Enter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nCard Client\n" << endl;
		cout << "\n------------------------------";
		cout << "\nFirst Name     = " << Client.FirstName ;
		cout << "\nLast Name      = " << Client.LastName ;
		cout << "\nEmail          = " << Client.Email ;
		cout << "\nPhoneNumber    = " << Client.PhoneNumber ;
		cout << "\nAccountNumber  = " << Client.GetAccountNumber() ;
		cout << "\nPinCode        = " << Client.PinCode ;
		cout << "\nAccountBalance = " << Client.AccountBalance ;
	}

public:

	static void ShowAddNewClient()
	{

		clsScreen::DrawTitleHeader("\t\t  Add New Client Screen");

		cout << "\n\tDo You Want Add New Client [Y/N] ? ";
		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			string AccountNumber;
			cout << "\n\tPlease Enter Account Number: ";
			AccountNumber = clsInputValidate::ReadString();

			while (clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\n\tThe Client with Account Number " << AccountNumber << " is exist, Enter another Account Number: ";
				AccountNumber = clsInputValidate::ReadString();
			}

			clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

			cout << "\n\n\tAdd New Client Info:\n" << endl;

			_ReadClientInfo(NewClient);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = NewClient.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\n\tClient Updated Successfully.\n";
				_PrintClientCard(NewClient);
				break;
			}

			case clsBankClient::enSaveResults::svFailedEmptyObject:
			{
				cout << "\n\tClient Update Failed Because Client is Empty.\n";
				break;
			}
			case clsBankClient::enSaveResults::svFaildAccountNumberExist:
			{
				cout << "\n\tClient Add New Failed Because Account Number is Exist.\n";
				break;
			}

			}
		}
		
	}


};

