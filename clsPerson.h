#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
    string _Firstname;
    string _Lastname;
    string _Email;
    string _Phone;
public:
    clsPerson() {

    }
    clsPerson(string Firstname, string Lastname, string Email, string Phone) {
        _Firstname = Firstname;
        _Lastname = Lastname;
        _Email = Email;
        _Phone = Phone;
    }
    string getFirstname() { return _Firstname; }
    void setFirstname(string Firstname) { _Firstname = Firstname; }
    _declspec(property(get = getFirstname, put = setFirstname))string Firstname;


    string getLastname() { return _Lastname; }
    void setLastname(string Lastname) { _Lastname = Lastname; }
    _declspec(property(get = getLastname, put = setLastname))string Lastname;


    string getEmail() { return _Email; }
    void setEmail(string Email) { _Email = Email; }
    _declspec(property(get = getEmail, put = setEmail))string Email;


    string getPhone() { return _Phone; }
    void setPhone(string Phone) { _Phone = Phone; }
    _declspec(property(get = getPhone, put = setPhone))string Phone;

    string Fullname() {
        return _Firstname + " " + _Lastname;
    }


    void Print()
    {
        cout << "Firstname:" << _Firstname << endl;
        cout << "Lastname :" << _Lastname << endl;
        cout << "fullname : " << Fullname() << endl;
        cout << "Email    : " << _Email << endl;
        cout << "Phone    : " << _Phone << endl;
    }


};

