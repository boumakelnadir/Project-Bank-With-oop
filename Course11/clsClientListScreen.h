#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreenHeader.h"

using namespace std;


class clsClientListScreen : protected clsScreen
{
private:
	
	
	static void _PrintClientRecordLine(clsBankClient C)
	{
		cout << "| " << left << setw(15) << C.GetAccountNumber();
		cout << "| " << left << setw(20) << C.FullName();
		cout << "| " << left << setw(12) << C.PhoneNumber;
		cout << "| " << left << setw(25) << C.Email;
		cout << "| " << left << setw(10) << C.GetPinCode();
		cout << "| " << left << setw(15) << fixed << setprecision(2) << C.GetAccountBalance();
	}

public:

	static void ShowClientList()
	{
		vector <clsBankClient> vClient = clsBankClient::GetClientsList();

		string Title = "\t\t  Clients List Screen";
		string SubTitle = "\t\t   (" + to_string(vClient.size()) + ") Client(s).";

		clsScreen::DrawTitleHeader(Title, SubTitle);

		cout << "\n\n\t|------------------------------------------------------------------------------------------------------------|\n";

		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(15) << "Account Balance";
		cout << "\n\t|------------------------------------------------------------------------------------------------------------|\n";

		if (vClient.size() == 0)
		{
			cout << "\n\t\t\tNo Clients Available In The System.\n";
		}
		else
		{
			for (clsBankClient& C : vClient)
			{
				cout << "\t";
				
				_PrintClientRecordLine(C);
				cout << endl;
			}
			cout << "\t|------------------------------------------------------------------------------------------------------------|\n";
			
		}
	}

};

