#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"


using namespace std;

class clsTransferMoneyLogScreen
{
private:

	static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecordList Record)
	{
		cout << "| " << left << setw(20) << Record.DateTime ;
		cout << "| " << left << setw(15) << Record.FromAccountNumber;
		cout << "| " << left << setw(15) << Record.ToAccountNumber;
		cout << "| " << left << setw(15) << Record.Amount ;
		cout << "| " << left << setw(15) << Record.FromAccountBalance ;
		cout << "| " << left << setw(15) << Record.ToAccountBalance ;
		cout << "| " << left << setw(15) << Record.UserName;
	}

public:

	static void ShowTransferMoneyLogScreen()
	{
		vector <clsBankClient::stTransferLogRecordList> TransferLogRecord = clsBankClient::GetTransferLogList();

		string title = "\t\t  Transfer Money Log Screen";
		string subTitle = "\t\t   (" + to_string(TransferLogRecord.size()) + ") Record(s).";

		clsScreen::DrawTitleHeader(title, subTitle);
		
		cout << "\n\n\t|---------------------------------------------------------------------------------------------------------------------|\n";
		cout << "\t| " << left << setw(20) << "Date Time";
		cout << "| " << left << setw(15) << "Acc.Num.From";
		cout << "| " << left << setw(15) << "Acc.Num.To";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "Balance From";
		cout << "| " << left << setw(15) << "Balance To";
		cout << "| " << left << setw(15) << "UserName";
		cout << "\n\t|---------------------------------------------------------------------------------------------------------------------|\n";

		if (TransferLogRecord.size() == 0)
		{
			cout << "\n\t\t\tNo Users Available In The System.\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecordList& U : TransferLogRecord)
			{
				cout << "\t";

				_PrintTransferLogRecord(U);
				cout << endl;
			}
			cout << "\t|---------------------------------------------------------------------------------------------------------------------|\n";

		}

	}


};


