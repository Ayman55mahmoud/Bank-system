#pragma once
#include<iostream>
using namespace std;
class clsScreen
{
protected:
	static void DrawscreenHeader(string titel, string Suptital = "") {
		cout << "\t\t\t\t\t_____________________________________________\n";
		cout << "\t\t\t\t\t\t" << titel;
		if (Suptital != "") {
			cout << "\n\t\t\t\t\t\t " << Suptital;
		}
		cout << "\n\t\t\t\t\t_____________________________________________\n";
	}

};
