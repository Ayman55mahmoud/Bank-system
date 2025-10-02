#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;
class clsDiposit:protected clsScreen
{
private:
    static void _print(clsBankClient client) {

        cout << "Client Card:\n";
        cout << "Firstname      : " << client.Firstname << endl;
        cout << "Lastname       : " << client.Lastname << endl;
        cout << "Fullname       : " << client.Fullname() << endl;
        cout << "Email          : " << client.Email << endl;
        cout << "Phone          : " << client.getPhone() << endl;
        cout << "Account Number : " << client.getAccountnumber() << endl;
        cout << "Account Balance: " << client.AccountBalance << endl;
        cout << "Pincode        : " << client.Pincode << endl;

    }

public:
    static void ShowDiposit() {
        DrawscreenHeader("Diposist a Client");
        string Accountnumber = "";
        cout << "enter The Acount Number:";
        Accountnumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientEcxist(Accountnumber)) {
            cout << "the Account Number Is Not Ecxist!,Enter Anather Acountnumber?\n";
            Accountnumber = clsInputValidate::ReadString();

        }
        clsBankClient client = clsBankClient::find(Accountnumber);
        _print(client);
        double Blance = 0;
        cout << "Please Enter Diposit amount?";
        cin >> Blance;
        char ch = 'n';
        cout << "\nAre You sure That Diposit This amount?(y/n)";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            client.Diposit(Blance);
            
        }
        cout << "\nthe Balance New Is :"<<client.AccountBalance<<endl;
        cout << "\nDone->)\n";



    }
};

