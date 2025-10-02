
#include <iostream>
#include<iomanip>
#include<fstream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<string>
#include"clsMianScreen.h"
//#include"clsUtil.h"

using namespace std;
void readclient(clsBankClient& client) {
    cout << "Enter The Firstname\n";
    
    client.Firstname = clsInputValidate::ReadString();
  
 
    cout << "Enter The Lasttname\n";
    
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







int main()
{
    clsMianScreen::ShowMainMenue();
    //cout << "f;dvjndjfv\njfdkvfdjvb\n\ndfjnv";
   
   // clsBankClient client = clsBankClient::find("M888");

   // client.Print();
    //ShowClientsList();
    //ShowClientsBalance();
   // UpdateClient();
    //Newclient();
    //Dleteclient();

   /* clsBankClient clint2 = clsBankClient::find("A777", "1234");
    clint2.Print();
    cout<< client.IsCientEcxist("A777");*/
   //UpdateClient();


    

    
    




	return 0;

}

   

