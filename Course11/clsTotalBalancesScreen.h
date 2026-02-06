#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreenHeader.h"
#include <vector>


using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintClientRecordBalancesLine(clsBankClient C)
	{
		cout << "\t| " << left << setw(15) << C.GetAccountNumber();
		cout << "\t| " << left << setw(40) << C.FullName();
		cout << "\t| " << left << setw(15) << fixed << setprecision(2) << C.GetAccountBalance();
	}

public:
	
	static void ShowTotalBalancesScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Total Balances Screen");
		
		vector <clsBankClient> vClient = clsBankClient::GetClientsList();

		cout << "\t|------------------------------------------------------------------------------------------------------------|\n";
		cout << "\t\t\t\t\tBalances List (" << vClient.size() << ") Client(s).\n";
		cout << "\t|------------------------------------------------------------------------------------------------------------|\n";
		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "\t| " << left << setw(40) << "Client Name";
		cout << "\t| " << left << setw(15) << "Account Balance";
		cout << "\n\t|------------------------------------------------------------------------------------------------------------|\n";

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClient.size() == 0)
		{
			cout << "\n\t\t\tNo Clients Available In The System.\n";
		}
		else
		{
			for (clsBankClient& C : vClient)
			{
				_PrintClientRecordBalancesLine(C);
				cout << endl;
			}
		}

		cout << "\t-------------------------------------------------------------------------------------------------------------|\n";

		cout << right << setw(61) << "\tTotal Balances : " << TotalBalances << endl;
		cout << right << setw(35) << "\tIn Words : " << clsUtil::NumberToText((int)TotalBalances) << "Dinar Algeria .\n";

		
	}

};

