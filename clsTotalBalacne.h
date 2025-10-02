#pragma once
#include<iostream>
#include"clsScreen.h"
#include"iomanip"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsTotalBalacne: protected clsScreen
{
private:
    static void _PrintClientRecordBalanceline(clsBankClient client) {
        cout << left << setw(15) << client.Accountnumber << "|";
        cout << left << setw(20) << client.Fullname() << "|";
        cout << client.AccountBalance << endl;
    }
public:
    static void ShowClientsBalance() {
        DrawscreenHeader("Total Balance Cient");
        vector<clsBankClient>vclient;
        vclient = clsBankClient::GetClientsList();
        cout << "\t\tBalance List(" << vclient.size() << ") Client(s).\n";
        cout << "___________________________________________________________\n\n";
        cout << left << setw(15) << "Account Number" << "|";
        cout << left << setw(20) << "Client Name" << "|";
        cout << "Blance\n";
        cout << "___________________________________________________________\n";
        double totalbalans = clsBankClient::GetTOtalBalance();

        if (vclient.size() == 0) {
            cout << "NO Client There it!";
        }
        else {
            for (clsBankClient c : vclient) {
                _PrintClientRecordBalanceline(c);
            }
        }

        cout << "___________________________________________________________\n";
        cout << "\t\tTotal Balance = " << totalbalans << endl;
        // cout << "\t\t(" << clsUtil::NumberToText(totalbalans)<<")" << endl;



    }
};

