#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


using namespace std;

class clsTransferMoneyScreen : protected clsScreen
{
private:

	static void PrintClientCard(clsBankClient Client)
	{
		cout << "\n\tClient Card:";
		cout << "\n\t__________________________";
		cout << "\n\tFull Name: " << Client.FullName();
		cout << "\n\tAccount Number: " << Client.GetAccountNumber();
		cout << "\n\tBalance: " << Client.GetAccountBalance() << "$";
		cout << "\n\t__________________________\n";
	}

public:

	static void ShowTransferMoneyScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Transfer Money Screen");

		cout << "\n\tPlease Enter The Account Number To Transfer From: ";
		string FromAccountNumber = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(FromAccountNumber))
		{
			cout << "\n\tAccount Number Not Found, Try Again.";
			return;
		}

		PrintClientCard(clsBankClient::Find(FromAccountNumber));

		cout << "\n\tPlease Enter The Account Number To Transfer To: ";
		string ToAccountNumber = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(ToAccountNumber))
		{
			cout << "\n\tAccount Number Not Found, Try Again.";
			return;
		}

		PrintClientCard(clsBankClient::Find(ToAccountNumber));

		cout << "\n\tPlease Enter The Amount To Transfer: ";
		double Amount = clsInputValidate::ReadDblNumber();

		clsBankClient ClientFrom = clsBankClient::Find(FromAccountNumber);

		while (Amount <= 0 || Amount > ClientFrom.AccountBalance)
		{
			cout << "\n\tYour Balance Is: " << ClientFrom.AccountBalance << "$";
			cout << "\n\tInvalid Amount, Try Again: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		cout << "\tAre You Sure You Want To Transfer " << Amount << "$ From " << ClientFrom.FullName() << " To " << clsBankClient::Find(ToAccountNumber).FullName() << "? (Y/N): ";
		char Answer;
		cin >> Answer;

		clsBankClient ClientTo = clsBankClient::Find(ToAccountNumber);

		if (toupper(Answer) == 'N')
		{
			return;
		}
		else
		{
			if (ClientFrom.Transfer(ClientTo, Amount))
			{
				cout << "\n\tTransfer Done Successfully.";


				PrintClientCard(ClientFrom);
				PrintClientCard(ClientTo);
			}
			else
			{
				cout << "\n\tTransfer Failed.";
				return;
			}

		}

	}

};