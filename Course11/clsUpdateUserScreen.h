#pragma once
#include <iostream>
#include "clsScreenHeader.h"
#include "clsInputValidate.h"
#include "clsUsers.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n\tEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n\tEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n\tEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n\tEnter Phone: ";
        User.PhoneNumber = clsInputValidate::ReadString();

        cout << "\n\tEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\n\tEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\n\tUser Card:";
        cout << "\n\t___________________";
        cout << "\n\tFirstName   : " << User.FirstName;
        cout << "\n\tLastName    : " << User.LastName;
        cout << "\n\tFull Name   : " << User.FullName();
        cout << "\n\tEmail       : " << User.Email;
        cout << "\n\tPhone       : " << User.PhoneNumber;
        cout << "\n\tUser Name   : " << User.UserName;
        cout << "\n\tPassword    : " << User.Password;
        cout << "\n\tPermissions : " << User.Permissions;
        cout << "\n\t___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\n\tDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\n\tDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            Permissions += clsUser::enPermissions::pListClient;
        }

        cout << "\n\tAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\n\tDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\n\tUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\n\tFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\n\tTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::PTransactions;
        }

        cout << "\n\tManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

public:

	static void ShowUpdateUserScreen()
	{
		clsScreen::DrawTitleHeader("\t\t  Update User Screen");

		string Username;
		cout << "\n\tPlease Enter Username : ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\n\tUsername Not Found, Enter Choose Another One"
				<< Username << " is not exist, Enter another Username : ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_PrintUser(User);

		cout << "\n\n\tDo You Want Update This User [Y/N] ? ";
		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) != 'Y')
			return;

		cout << "\n\n\tUpdate User Info:\n" << endl;

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n\tUser Updated Successfully.\n";
			_PrintUser(User);
			break;
		}

		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\n\tUser Update Failed Because User is Empty.\n";
			break;
		}
		}
	}

};

