#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

using namespace std;

class clsTransferLoginHistory
{

public:

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	
	static vector<stLoginRegisterRecord> GetLoginHistory()
	{
		vector<stLoginRegisterRecord> vLoginHistory;
		fstream MyFile;
		MyFile.open("LoginHistory.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vLoginHistory.push_back(clsUser::_ConvertLinetoLoginRegisterRecord(Line));
			}
			MyFile.close();
		}
		return vLoginHistory;
	}

};