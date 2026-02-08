#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& client)
    {
        cout << "\n\tEnter FirstName: ";
        client.FirstName = clsInputValidate::ReadString();

        cout << "\n\tEnter LastName: ";
        client.LastName = clsInputValidate::ReadString();

        cout << "\n\tEnter Email: ";
        client.Email = clsInputValidate::ReadString();

        cout << "\n\tEnter Phone: ";
        client.PhoneNumber = clsInputValidate::ReadString();

        cout << "\n\tEnter PinCode : ";
        client.PinCode = clsInputValidate::ReadString();

        cout << "\n\tEnter Balance : ";
        client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

    static void _PrintClientCard(clsBankClient& Client)
    {
        cout << "\n\tClient Card:";
        cout << "\n\t___________________";
        cout << "\n\tAccount Number : " << Client.GetAccountNumber();
        cout << "\n\tFirstName   : " << Client.FirstName;
        cout << "\n\tLastName    : " << Client.LastName;
        cout << "\n\tFull Name   : " << Client.FullName();
        cout << "\n\tEmail       : " << Client.Email;
        cout << "\n\tPhone       : " << Client.PhoneNumber;
        cout << "\n\tPinCode     : " << Client.PinCode;
        cout << "\n\tAccount Balance    : " << Client.AccountBalance;
        cout << "\n\t___________________\n";

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

