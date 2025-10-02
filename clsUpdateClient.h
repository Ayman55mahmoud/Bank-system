#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsUpdateClient:public clsScreen
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
    static void UpdateClient() {
        DrawscreenHeader("Naw You Update Client");
        string Accountnumber = "";
        cout << "Bleas Enter The Accountnumber?\n";
        cin >> Accountnumber;
        while (!clsBankClient::IsClientEcxist(Accountnumber)) {
            cout << "Bleas Enter The Corect Accountnumebr .\n";
            Accountnumber = clsInputValidate::ReadString();

        }
        clsBankClient client = clsBankClient::find(Accountnumber);
        client.Print();
        cout << "Update Client Info:\n";
        char ch = 'n';
        cout << "Do You Want Update This Client!(Y/N)\n";
        cin >> ch;

        if (ch == 'y' || ch == 'Y') {
            readclient(client);
            clsBankClient::ensave svensave;
            svensave = client.save();
            switch (svensave) {
            case clsBankClient::ensave::svfildEmpetyopject: {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsBankClient::ensave::svsacceeded: {
                cout << "\nAccount Updated Successfully :-)\n";
                _print(client);
                break;
            }
            }
       }

    }

};

