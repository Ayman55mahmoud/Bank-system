#pragma once
#include"iostream"
#include"clsPerson.h"
#include"clsString.h"
#include"string"
#include<fstream>
using namespace std;

class clsUsers:public clsPerson
{
private:
	enum enMode{EnpatyMod=0,UpdateMod=1,NewMode=2};
	enMode _Mode;
	string _userName;
	string _Password;
	int _permissions;
	bool _MarkedForDelete=false;
	static string _CovertUserOpjectToLine(clsUsers User, string u = "#//#") {
		string users = "";
		users = User.Firstname + u;
		users += User.Lastname + u;
		users += User.Email + u;
		users += User.Phone + u;
		users += User._userName + u;
		users += User._Password + u;
		users +=to_string (User._permissions) ;
		return users;


	}
	static clsUsers _ConvertLintToUserOpject(string line ,string u="#//#") {
		vector<string>vUser;
		vUser = clsstring::Split(line, u);
		return clsUsers(enMode::UpdateMod, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5],
			stoi(vUser[6]));
	}
	static vector<clsUsers>_LoadUsersDataFromFile() {
		vector<clsUsers>vuser;
		fstream Myfile;
		Myfile.open("User.txt", ios::in);
		if (Myfile.is_open()) {
			string line;
			while (getline(Myfile, line)) {
				clsUsers u = _ConvertLintToUserOpject(line);
				vuser.push_back(u);
			}
			Myfile.close();
		}
		return vuser;

	}
	static vector<clsUsers>_SaveUsersDataToFile(vector<clsUsers> vusers) {
		fstream Myfile;
		Myfile.open("User.txt", ios::out);
		if (Myfile.is_open()) {
			string line;
			for (clsUsers& u : vusers) {
				if (u._MarkedForDelete == false) {
					line = _CovertUserOpjectToLine(u);
					Myfile << line << endl;
				}
			}
			Myfile.close();

		}
	}
	static clsUsers _GetEmptyUserObject()
	{
		return clsUsers(enMode::EnpatyMod, "", "", "", "", "", "", 0);
	}
	void _Update() {
		vector<clsUsers>vuser;
		vuser = _LoadUsersDataFromFile();
		for (clsUsers& u : vuser) {
			if (u._userName == _userName) {
				u = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vuser);
	}

	void _AddNew() {
		_AddDataLineToFile(_CovertUserOpjectToLine(*this));
	}

	void _AddDataLineToFile(string LIne) {
		fstream Myfile;
		Myfile.open("User.txt", ios::out | ios::app);
		if (Myfile.is_open()) {
			Myfile << LIne << endl;
			Myfile.close();
		}
	}



public:
	clsUsers(enMode Mode, string Fristname, string Lastmane, string Email, string Pohne, string Username,
		string Password, int permissions) :clsPerson(Fristname, Lastmane, Email, Pohne) {
		_userName = Username;
		_Password = Password;
		_Mode = Mode;
		_permissions = permissions;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EnpatyMod);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _userName;
	}

	void SetUserName(string UserName)
	{
		_userName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_permissions = Permissions;
	}

	int GetPermissions()
	{
		return _permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUsers find(string Username) {
		fstream Myfile;
		Myfile.open("User.txt", ios::in);
		if (Myfile.is_open()) {
			string line;
			while (getline(Myfile, line)) {
				clsUsers u = _ConvertLintToUserOpject(line);
				if (u.UserName == Username) {
					Myfile.close();
					return u;
				}
			}
		}
		return _GetEmptyUserObject();
	}
	static clsUsers find(string username, string password) {
		fstream Myfile;
		Myfile.open("User.txt", ios::in);
		if (Myfile.is_open()) {
			string line;
			while (getline(Myfile, line)) {
				clsUsers u = _ConvertLintToUserOpject(line);
				if (u.UserName == username || u.Password == password) {
					Myfile.close();
					return u;
				}
			}
		}
		return _GetEmptyUserObject();
	}
	static bool IsUserExit(string name) {
		clsUsers u = clsUsers::find(name);
		return (!u.IsEmpty());
	}
	static clsUsers GetAddNewUserObject(string UserName)
	{
		return clsUsers(enMode::NewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	bool Delete() {
		vector<clsUsers>u;
		u = _LoadUsersDataFromFile();
		for (clsUsers& x : u) {
			if (x.UserName == _userName) {
				x._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(u);
		 *this = _GetEmptyUserObject();
		return true;

	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EnpatyMod:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMod:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::NewMode:
		{
			//This will add new record to file or database
			if (clsUsers::IsUserExit(_userName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMod;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}


};

