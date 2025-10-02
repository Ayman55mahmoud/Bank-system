#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "clsPerson.h"
#include"clsstring.h"
class clsBankClient :public clsPerson
{
private:
    enum enmode { Empetymode = 0, Updatemode = 1,newclientmod=2 };
    enmode _Mode=enmode::Empetymode;
    string _Accountnumber;
    string _Pincode;
    float _AccountBalance=0;
    bool _MarkedforDlete = false;
    static clsBankClient _Convertlinetoclientopject(string line, string seperator = "#//#") {
        vector<string>vClient;
        vClient = clsstring::Split(line, seperator);
        if (vClient.size() < 7) {  // ÊÃßÏ Ãä ÚÏÏ ÇáÚäÇÕÑ ßÇİò
            cerr << "Error: Not enough data in the line!" << endl;
            return clsBankClient(); // Ãæ ããßä ÊÑãí ÇÓÊËäÇÁ
        }
        return clsBankClient(enmode::Updatemode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5],
            stod(vClient[6]));
    }
    static clsBankClient GetEmpetyMode() {
        return clsBankClient(enmode::Empetymode, "", "", "", "", "", "", 0);

    }
    static string _convertopjectclienttoline( clsBankClient &client, string seperator = "#//#") {
        string line = "";
        

        line = client.Firstname + seperator;
        line = line+client.Lastname + seperator;
        line = line+client.Email + seperator;
        line = line+client.getPhone() + seperator;
        line = line+client.getAccountnumber() + seperator;
        line = line+client._Pincode + seperator;
        line = line+to_string(client._AccountBalance);
        return line;


    }

    static vector<clsBankClient>_loadDataformfile() {
        vector<clsBankClient>_vclient;
        fstream Myfile;
        Myfile.open("Myfile.txt", ios::in);
        if (Myfile.is_open()) {
            string line;
            while (getline(Myfile, line)) {
                clsBankClient client = _Convertlinetoclientopject(line);
                _vclient.push_back(client);

            }
            Myfile.close();
        }
        return _vclient;
    }
    void _saveDatatofile(vector<clsBankClient>_vclient) {
        fstream Myfile;
        Myfile.open("Myfile.txt", ios::out);
        if (Myfile.is_open()) {
            string line;
            for (clsBankClient &c : _vclient) {
                if (c._MarkedforDlete==false) {
                    line = _convertopjectclienttoline(c);
                    Myfile << line << endl;

                }
            }
            Myfile.close();
        }

    }
    void _Update() {
        vector<clsBankClient>_vclient;
        _vclient = _loadDataformfile();
        for (clsBankClient& c : _vclient) {
            //ÇáãÚáæãÇÊ ÇáŞÏíãå İì _vclient ÈãÃä Çá ÇßæäÊ äãÈÑ ãÔ ÈíÊÛÑ ÈäÔæİ Çì Úãíá ÇáßæääÊ äãÈÑ ÈÊÇÚå ãÔÇÈå áÈÊÇÚ ÇáÚãíá
          // Çááì ÇÍäÇ ãÛíÑíä ãÚáæãÇÊå æÈÚÏíä äÓÇæì ÇácÈ ÇáßáíäÊ Çááì ÇÍÇäÇ ÔÛÊáíä Úáíå Çááì åæÇ ãÛíÑíä ãÚáæãÇÊå 
          //Çæá ãäÚãá ßÏÇ ãÚ ÇácÇá _vclient åÊÊÛíÑ áæÍÏåÇ æåÊÇÎÏ ÇáãÚáæãÇÊ ÇáÌÏíÏå ÚáÔÇä Çác py refrance.
            
            if (c.getAccountnumber() == _Accountnumber) {
                c = *this;
                break;
            }
        }
        _saveDatatofile(_vclient);
    }
    void _Addnew() {
        _Addnewdatainfile(_convertopjectclienttoline(*this));
    }
    void _Addnewdatainfile(string client) {
        fstream Myfile;
        Myfile.open("Myfile.txt",ios::out| ios::app);
        if (Myfile.is_open()) {
            Myfile << client << endl;
            Myfile.close();
         
        }
    }


public:
    clsBankClient() {
         
    }
    clsBankClient(enmode Mode, string Firstname, string Lastname, string Email, string Phone, string Accountnumber
        , string Pincode, float AccountBalance) :clsPerson(Firstname, Lastname, Email, Phone) {
        _Mode = Mode;
        _AccountBalance = AccountBalance;
        _Accountnumber = Accountnumber;
        _Pincode = Pincode;

    }
    bool Isempty() {
        return _Mode == enmode::Empetymode;
    }
    


    string getAccountnumber() { return _Accountnumber; }
   // void setAccountnumber(string Accountnumber) { _Accountnumber = Accountnumber; }
    __declspec(property(get = getAccountnumber)) string Accountnumber;


    string getPincode() { return _Pincode; }
    void setPincode(string Pincode) { _Pincode = Pincode; }
    __declspec(property(get = getPincode, put = setPincode)) string Pincode;


    float getAccountBalance() { return _AccountBalance; }
    void setAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }
    __declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;


   /* void Print()
    {
        cout << "Client Card:\n";
        cout << "Firstname      : " << Firstname << endl;
        cout << "Lastname       : " << Lastname << endl;
        cout << "Fullname       : " << Fullname() << endl;
        cout << "Email          : " << Email << endl;
        cout << "Phone          : " << getPhone() << endl;
        cout << "Account Number : " << _Accountnumber << endl;
        cout << "Account Balance: " << _AccountBalance << endl;
        cout << "Pincode        : " << _Pincode << endl;
    }*/
    static clsBankClient find(string Accountnumber) {
        fstream Myfile;
        Myfile.open("Myfile.txt", ios::in);
        string line;
        if (Myfile.is_open()) {
            
            while (getline(Myfile, line)) {
                clsBankClient Client = _Convertlinetoclientopject(line);
                if (Client.getAccountnumber() == Accountnumber) {
                    Myfile.close();
                    return Client;
                }


            }
            Myfile.close();
        }
        return GetEmpetyMode();

    }
    static clsBankClient find(string Accountnumber, string Pincode) {
        fstream Myfile;
        string line;
        Myfile.open("Myfile.txt", ios::in);
        if (Myfile.is_open()) {
            while (getline(Myfile, line)) {
                clsBankClient client = _Convertlinetoclientopject(line);
                if (client._Accountnumber == Accountnumber && client._Pincode == Pincode) {
                    Myfile.close();
                    return client;
                }
            }
            Myfile.close();
        }
        return GetEmpetyMode();
    }
    static enum ensave { svfildEmpetyopject = 0, svsacceeded = 1 }; 
    ensave save() {
        switch (_Mode) {
        case enmode::Updatemode: {
            _Update();
            return ensave::svsacceeded;
            break;

        }
        case enmode::Empetymode: {
            return ensave::svfildEmpetyopject;
        }
        case enmode::newclientmod: {
            _Addnew();
            _Mode = enmode::Updatemode;


            return ensave::svsacceeded;
            break;
        }


        }
    }
    static clsBankClient Newclient(string accountnumber) {
        return clsBankClient(enmode::newclientmod, "", "", "", "", accountnumber, "", 0);
    }
    bool Dlete() {
        vector<clsBankClient>vclient;
        vclient = _loadDataformfile();
        for (clsBankClient& c : vclient) {
            if (c.Accountnumber == _Accountnumber) {
                c._MarkedforDlete = true;
                break;
            }
        }
        _saveDatatofile(vclient);
        *this=GetEmpetyMode( );
        return true;
    }
    static vector<clsBankClient>GetClientsList() {
        return _loadDataformfile();
    }
    static double GetTOtalBalance() {
        vector<clsBankClient>vclient;
        vclient = _loadDataformfile();
        double totalBalance = 0;
        for (clsBankClient c : vclient) {
            totalBalance += c.AccountBalance;
        }
        return totalBalance;
    }
     void Diposit(double d) {
        _AccountBalance += d;
        save();
    }
     bool Withdrow(double d) {
         if (d > _AccountBalance) {
             return false;
         }
         else {
             _AccountBalance -= d;
             save();
             return true;
         }
         
    }
   
    


    static bool IsClientEcxist(string Accountnumber) {
        clsBankClient client = clsBankClient::find(Accountnumber);
        cout << "Checking Account: " << Accountnumber << " -> Found: " << !client.Isempty() << endl;

        return  ( !client.Isempty());
    }

};


