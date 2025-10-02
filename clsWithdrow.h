#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;
class clsWithdrow :protected clsScreen
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
    static void ShowWithdrow() {
        DrawscreenHeader("Withdrow a Client");
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
        cout << "Please Enter Withdrow amount?";
        cin >> Blance;
        char ch = 'n';
        cout << "\nAre You sure That Withdrow This amount?(y/n)";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            if (client.Withdrow(Blance)) {
                cout << "the New Balance : " << client.AccountBalance << endl;
                cout << "Done->)\n";
            }
            else {
                cout << "Cannot Withdrow!\n";
                cout << "the withdrow: " << Blance << endl;
                cout << "the Acount Balance: " << client.AccountBalance << endl;
            }

        }
        


    }
};

