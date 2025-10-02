#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsNewClient:public clsScreen
{
private:
    static void readclient(clsBankClient& client) {
        cout << "Enter The Firstname\n";

        client.Firstname = clsInputValidate::ReadString();


        cout << "Enter The Lastname\n";

        client.Lastname = clsInputValidate::ReadString();

        cout << "Enter The Emial\n";
        client.Email = clsInputValidate::ReadString();

        cout << "Enter The Phone\n";
        client.Phone = clsInputValidate::ReadString();
        /* cout << "Enter the Accountnumbre\n";
         client.Accountnumber = clsInputValidate::ReadString();*/


        cout << "Enter The Pincode\n";
        client.Pincode = clsInputValidate::ReadString();

        cout << "Enter The Accountpalance\n";

        client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }
    static void _print(clsBankClient client) {
        
            cout << "Client Card:\n";
            cout << "Firstname      : " <<client.Firstname << endl;
            cout << "Lastname       : " << client.Lastname << endl;
            cout << "Fullname       : " << client.Fullname() << endl;
            cout << "Email          : " << client.Email << endl;
            cout << "Phone          : " << client.getPhone() << endl;
            cout << "Account Number : " << client.getAccountnumber()<< endl;
            cout << "Account Balance: " << client.AccountBalance<< endl;
            cout << "Pincode        : " << client.Pincode << endl;
        
    }
public:
    static void Newclient() {
        DrawscreenHeader("Now You Add a New Client");
        string Accountnumber = "";
        cout << "Enter a New Accountnumber.\n";
        Accountnumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientEcxist(Accountnumber)) {
            cout << "Enter Anther Accountnumber Becouse is Found.\n";
            cin >> Accountnumber;
        }
        clsBankClient client = clsBankClient::Newclient(Accountnumber);

        readclient(client);
        client.save();
        _print(client);
        cout << "Done->)";



    }

};

