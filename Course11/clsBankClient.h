#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

using namespace std;

const string ClientFileName = "Clients.txt";

class clsBankClient : public clsPerson
{
private:

	enum enMode{ EmptyMode , UpdateMode , AddNewMode };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClinetObject(string Line, string Delim = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Delim);

		return clsBankClient(enMode::UpdateMode, vClientData[0],
			vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Delim = "#//#")
	{
		string ClientObjectToLine = "";

		ClientObjectToLine += Client.FirstName + Delim;
		ClientObjectToLine += Client.LastName + Delim;
		ClientObjectToLine += Client.Email + Delim;
		ClientObjectToLine += Client.PhoneNumber + Delim;
		ClientObjectToLine += Client.GetAccountNumber() + Delim;
		ClientObjectToLine += Client.GetPinCode() + Delim;
		ClientObjectToLine += to_string(Client.GetAccountBalance());

		return ClientObjectToLine;   
	}

	static vector <clsBankClient> _LoadDataClientsFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(ClientFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClinetObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveDataClientsToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open(ClientFileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& Client : vClients)
			{
				if (Client._MarkForDelete == false)
				{
					string DataLine = _ConvertClientObjectToLine(Client);

					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open(ClientFileName, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadDataClientsFromFile();

		for (clsBankClient& Client : _vClients)
		{
			if (Client.GetAccountNumber() == this->GetAccountNumber())
			{
				Client = *this;
				break;
			}
		}
		_SaveDataClientsToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber,
		string AccountNumber, string PinCode, double AccountBalance) 
		:clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_PinCode = PinCode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;
	

	static clsBankClient Find(string AccountNumber)
	{
		/*vector<clsBankClient> vClients;*/

		fstream MyFile;
		MyFile.open(ClientFileName, ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClinetObject(Line);

				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();

					return Client;
				}

				//vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber ,string PinCode)
	{
		/*vector<clsBankClient> vClients;*/

		fstream MyFile;
		MyFile.open(ClientFileName, ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClinetObject(Line);

				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();

					return Client;
				}

				//vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}
	
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svSucceeded = 0, svFailedEmptyObject = 1 , svFaildAccountNumberExist = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case enMode::EmptyMode:
			{
				if (IsEmpty())
				{
					return enSaveResults::svFailedEmptyObject;
				}
			}

			case enMode::UpdateMode:
			{
				_Update();
				return enSaveResults::svSucceeded;
			}

			case enMode::AddNewMode:
			{
				if (clsBankClient::IsClientExist(_AccountNumber))
				{
					return enSaveResults::svFaildAccountNumberExist;
				}
				else
				{
					_AddNew();
					_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}
			}

		};
	};

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		
		vector <clsBankClient> vClients;
		vClients = _LoadDataClientsFromFile();

		for (clsBankClient& Client : vClients)
		{
			if (Client.GetAccountNumber() == this->GetAccountNumber())
			{
				Client._MarkForDelete = true;
				break;
			}
		}
		
		_SaveDataClientsToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadDataClientsFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients;
		vClients = GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.GetAccountBalance();
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}



};

