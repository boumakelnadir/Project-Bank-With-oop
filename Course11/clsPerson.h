#pragma once
#include<iostream>


using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:
	
	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_PhoneNumber = PhoneNumber;
		_Email = Email;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}

	_declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}

	_declspec(property(get = GetLastName, put = SetLastName))string LastName;
	
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}

	_declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}

	_declspec(property(get = GetPhoneNumber, put = SetPhoneNumber))string PhoneNumber;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};


