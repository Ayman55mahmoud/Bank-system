#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsNewClient.h"
#include"clsDeletClient.h"
#include"clsUpdateClient.h"
#include"FindClient.h"
#include"clsTransactionScreen.h"
#include"clsManageUsrer.h"
using namespace std;
class clsMianScreen:protected clsScreen 
{
private:
	enum enMianMunueOption {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8

	};
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
        
       
    }
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }


    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsNewClient::Newclient();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeletClient::Dleteclient();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClient::UpdateClient();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        FindClient::ShowFindClient();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionScreen::ShowTransacionScreen();
    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }



	static void _PerfromMianMenueOption(enMianMunueOption MianMenueOption) {
		switch (MianMenueOption) {
		case enMianMunueOption::eAddNewClient: {
			system("cls");
            _ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
        case enMianMunueOption::eDeleteClient: {
            system("cls");
            
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMianMunueOption::eExit: {
            system("cls");
            _ShowEndScreen();
            _GoBackToMainMenue();
            break;

        }
        case enMianMunueOption::eFindClient: {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        }
        case enMianMunueOption::eListClients: {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        }
        case enMianMunueOption::eManageUsers: {
            system("cls");
            _ShowManageUsersMenue();        
            _GoBackToMainMenue();
            break;
        }
        case enMianMunueOption::eShowTransactionsMenue: {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        }
        case enMianMunueOption::eUpdateClient: {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        }


                                                    
		}
	}
    public:
        static void ShowMainMenue()
        {

            system("cls");
            DrawscreenHeader("\tMian Menue");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerfromMianMenueOption((enMianMunueOption)_ReadMainMenueOption());
        }
};

