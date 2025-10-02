#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDiposit.h"
#include"clsWithdrow.h"
#include"clsTotalBalacne.h"
//#include"clsMianScreen.h"
using namespace std;
class clsTransactionScreen:protected clsScreen
{
private:
	enum enenum{Diposit=1,Withdraw=2,TotalBalance=3,mainmenue=4};
	static short _readnum() {
		int num = 0;
		cout <<  "\t\t\t\t\tChoose What Do you Want to Do [1,4]";
		num = clsInputValidate::ReadIntNumberBetween(1, 4,"Enter the number between[1,4]");
		return num;
	}
	static void _Goback() {
		cout << "Prees Any Key To Go Back Transaction Menue...\n";
		system("pause>0");
		ShowTransacionScreen();

	}

	static void _ShowDiposit() {
		//cout << "Diposit>>>>>>>>>>>>>>>>>\n";
		clsDiposit::ShowDiposit();
	}
	static void _ShowWithdraw() {
		//cout << "Withdraw>>>>>>>>>>>>\n";
		clsWithdrow::ShowWithdrow();
	}
	static void _ShowTotalBalance() {
		//cout << "totalbalnce<<<<<<<<<<<<<<<<<<\n";
		clsTotalBalacne::ShowClientsBalance();
	}
	static void _Showmainmenue() {
		cout << "mianmenue<<<<<<<<<<<<<<<<\n";
		//clsMianScreen::ShowMainMenue();
	}

	static void _implement(enenum choose) {
		switch (choose) {
		case enenum::Diposit: {
			system("cls");
			_ShowDiposit();
			_Goback();
			break;
		}
		case enenum::Withdraw: {
			system("cls");
			_ShowWithdraw();
			_Goback();
			break;
		}
		case enenum::TotalBalance: {
			system("cls");
			_ShowTotalBalance();
			_Goback();
			break;
		}
		case enenum::mainmenue: {
			//system("cls");
			//_Showmainmenue();
			//_Goback();
			//break;
		}

		}

	}
public:
	static void ShowTransacionScreen() {
		system("cls");
		DrawscreenHeader("Transaction Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Diposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		_implement((enenum)_readnum());
	}
};

