#include <iostream>
#include "clsScreenHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawMoneyScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber;

		cout << "\n\tPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		clsScreen::DrawTitleHeader("\t\tWithdraw Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\tClient with Account Number Not Found, Choose Another One : ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);

		double Amount = 0;
		cout << "\n\tPlease Enter Withdraw Amount : ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\n\tare You Sure Want to Perform This Transaction [Y/N] : ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			
			if (Client.Withdraw(Amount))
			{
				cout << "\n\tTransaction Done Successfully.\n";
				cout << "\tNew Balance is : " << Client.AccountBalance << "\n";
			}
			else{
				cout << "\n\tTransaction Failed.\n";
				cout << "\n\tYour Balance is : " << Client.AccountBalance ;
				cout << "\n\tWithdraw Amount is : " << Amount << "\n";
			}

		}
		else{
			cout << "\n\tTransaction Canceled.\n";
		}

	}
};

