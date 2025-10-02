#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class FindClient:protected clsScreen
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
    static void ShowFindClient() {
        DrawscreenHeader("Find Client Screen");
        cout << "Pleas Enter The Acount Number:";
        string Acountnumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientEcxist(Acountnumber)) {
            cout << "Enter the cotect Acount number:";
            Acountnumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::find(Acountnumber);
        if (!client.Isempty()) {
            cout << "Client is Found\n";
            
        }
        else cout << "client isnot found\n";
        
        _print(client);
    }
};

