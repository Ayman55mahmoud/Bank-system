#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
using  namespace std;
class clsClientListScreen:public clsScreen
{
private:
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.Accountnumber;
        cout << "| " << setw(20) << left << Client.Fullname();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.Pincode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static void ShowClientsList()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string tital = " Client List Screen.";
        string Suptital = "(" + to_string(vClients.size()) + ")" + "Client (S).";
         
        DrawscreenHeader(tital, Suptital);
        //cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

