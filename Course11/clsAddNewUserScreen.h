#pragma once

#include <iostream>
#include "clsScreenHeader.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
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
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\n\tManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

		cout << "\n\tLogin Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
        {
			Permissions += clsUser::enPermissions::pLogInRegister;
		}

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        clsScreen::DrawTitleHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }



};

