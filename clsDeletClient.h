#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;

class clsDeletClient:public clsScreen
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
    static void Dleteclient() {
        char Answer = 'y';
        while (Answer == 'y' || Answer == 'Y') {
        DrawscreenHeader("Naw You Delet a Client.");
        string Accountnumber = "";
        cout << "Enter Accountnumber that do you went Dlete it.\n";
        Accountnumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientEcxist(Accountnumber)) {
            cout << "Enter Anther Accountnumber Becouse Isnot Founde.\n";
            Accountnumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::find(Accountnumber);
        client.Print();
        
        cout << "Are You Sure You Went Dleted This Client ? (y/n).\n";
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y') {
            if (client.Dlete()) {
                cout << "Dleted Is Saccssecfly ->)\n";
                _print(client);
            }
            else cout << "Dletes not saccssecfly.\n";
            }
            
        }
        cout << "Do you want to delete another client? (y/n): ";
        cin >> Answer;



    }

};

