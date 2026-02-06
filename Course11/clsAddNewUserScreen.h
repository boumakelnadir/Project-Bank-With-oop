#pragma once
#include<iostream>
#include<string>
#include"clsScreenHeader.h"
#include"clsUsers.h"


using namespace std;

class clsAddNewUserScreen : public clsScreen
{
private:

	static int _ReadPermissionsToSet()
	{
		int permissions = 0;
		char Choice = 'n';

		cout << "\n\t\t\t\t\tPlease choose user permissions: \n";
		
		cout << "\n\t\t\t\t\tDo you want to get all permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pAll;
			return permissions;
		}

		cout << "\n\t\t\t\t\tDo you want to give Access to :  ";

		cout << "\n\t\t\t\t\tDo you want to get List Client permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pListClient;
		}

		cout << "\n\t\t\t\t\tDo you want to get Add New Client permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pAddNewClient;
		}

		cout << "\n\t\t\t\t\tDo you want to get Delete Client permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pDeleteClient;
		}

		cout << "\n\t\t\t\t\tDo you want to get Update Client permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pUpdateClient;
		}

		cout << "\n\t\t\t\t\tDo you want to get Find Client permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pFindClient;
		}

		cout << "\n\t\t\t\t\tDo you want to get Transactions permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::PTransactions;
		}

		cout << "\n\t\t\t\t\tDo you want to get Manage Users permissions :  ";
		cin >> Choice;
		if (Choice == 'y' || Choice == 'Y')
		{
			permissions += clsUser::pManageUsers;
		}

		return permissions;
	}
	
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\n\t\t\t\t\tPlease enter user first name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\n\t\t\t\t\tPlease enter user last name: ";
		User.LastName = clsInputValidate::ReadString();
		
		cout << "\n\t\t\t\t\tPlease enter user email: ";
		User.Email = clsInputValidate::ReadString();
		
		cout << "\n\t\t\t\t\tPlease enter user phone: ";
		User.PhoneNumber = clsInputValidate::ReadString();
		
		cout << "\n\t\t\t\t\tPlease enter user name: ";
		User.UserName = clsInputValidate::ReadString();
		
		cout << "\n\t\t\t\t\tPlease enter user password: ";
		User.Password = clsInputValidate::ReadString();
		
		User.Permissions = _ReadPermissionsToSet();

	}

	static void _PrintUser(clsUser& U)
	{
		cout << "| " << left << setw(25) << U.FullName();
		cout << "| " << left << setw(15) << U.PhoneNumber;
		cout << "| " << left << setw(20) << U.Email;
		cout << "| " << left << setw(20) << U.Password;
		cout << "| " << left << setw(15) << U.Permissions;
	}

public:
	static void ShowAddNewUserScreen()
	{

		clsScreen::DrawTitleHeader("\t\tAdd New User Screen");
		
		cout << "\t\t\tPlease Enter UserName : ";
		string UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n\t\t\tUserName is already exist, please enter another UserName : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
			case clsUser::svFaildEmptyObject:
			{
				cout << "\n\t\t\tError: User Info Is Empty.\n";
				break;
			}
			case clsUser::svSucceeded:
			{
				cout << "\n\t\t\tUser Added Successfully.\n";
				_PrintUser(NewUser);
				break;
			}
				break;
			case clsUser::svFaildUserExists:
			{
				cout << "\n\t\t\tError: UserName is already exist.\n";
				break;
			}
			
		}

	}
};

