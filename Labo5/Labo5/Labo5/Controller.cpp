#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>    
#include "sstream"

#include "Customer.h"
#include "Article.h"
#include "Invoice.h"

#include "EmployeeUtils.h"
#include "TireCenterUtils.h"
#include "FileProcessing.h"

const char logo[] =
"  @@@@@@@  @   @@@@@@@     @@@@@@@     @@@@     @@@@@@@@  @      @   @@@@@@@   @@@@@@@   @@@@@@@    \n"
"     @     @@  @@    @@@  @@         @@@  @@@   @         @@@    @      @     @@@        @@    @@@  \n"
"     @     @@  @@    @@@   @@@@@@@  @@          @@@@@@@   @ @@@  @      @     @@@@@@@@   @@    @@   \n"
"     @     @@  @@@@@@@     @        @@          @@        @   @@ @      @     @@@        @@ @@@     \n"
"     @     @@  @@    @@@  @@         @@@  @@@   @         @    @@@      @     @@@        @@   @@@   \n"
"     @     @@  @@     @@   @@@@@@@@    @@@@     @@@@@@@@  @      @      @      @@@@@@@   @@     @@  \n";

using namespace std;

//files
fstream employeesFilep;
fstream customersFilep;
fstream articlesFilep;
fstream invoicesFilep;

int main() {
	//CMD color White
	setTextColor(CMD_COLOR_WHITE);

	//flags
	int exitProgramFlag = 1;

	//variables
	string username = "";
	string userType = "";
	int option = 0;
	string line;

	vector<Customer> customers;
	vector<Article> articles;
	vector<Invoice> invoices;

	//print logo
	setTextColor(CMD_COLOR_BLUE);
	cout << logo << endl << endl;
	setTextColor(CMD_COLOR_WHITE);
	cout << "(Enter fullscreen for best experience)" << endl;

	//open "Employees database"
	employeesFilep.open("Employees.txt", ios::in);
	
	if (!employeesFilep) {
		cout << "Couldn't open databases -> exiting" << endl;
		exitProgramFlag = 0;
	}
	else {
		//continue the log in if succesfull
		int employeeIndex = 0;
		string availableUsers[50][2];

		cout << "List op available employees:" << endl;
		setTextColor(CMD_COLOR_GREEN);
		while (getline(employeesFilep, line)) { // Read each line from the file
			istringstream lineStream(line);
			lineStream >> availableUsers[employeeIndex][0] >> availableUsers[employeeIndex][1];
			cout << availableUsers[employeeIndex][0] << endl;
			employeeIndex++;
		}
		setTextColor(CMD_COLOR_WHITE);

		cout << "Log in" << endl << "username: ";
		cin >> username;

		for (int i = 0; i < 50; i++) {
			if (username == availableUsers[i][0]) {
				userType = availableUsers[i][1];
			}
		}
	}
	employeesFilep.close();

	//read data from files
	readInvoiceFromFile(&invoices);
	readArticlesFromFile(&articles);
	readCustomerFromFile(&customers);

	//main program
	while (exitProgramFlag)
	{
		//Options screen
		if (userType == "A" || userType == "E") {
			cout << endl << "welkom " + username << endl;
			cout << "\033[1;33m 0 \033[1;37m: exit program" << endl;
		}

		// If Owner
		if (userType == "A") {
			cout << "\033[1;33m 1 \033[1;37m: add article" << endl;
			cout << "\033[1;33m 2 \033[1;37m: delete article" << endl;
			cout << "\033[1;33m 3 \033[1;37m: delete customer" << endl;
		}

		//If Employee
		if (userType == "A" || userType == "E") {
			cout << "\033[1;33m 4 \033[1;37m: change article" << endl;
			cout << "\033[1;33m 5 \033[1;37m: check invoices" << endl;
			cout << "\033[1;33m 6 \033[1;37m: place order" << endl;
			cout << "\033[1;33m 7 \033[1;37m: change customer" << endl;
			cout << "\033[1;33m 8 \033[1;37m: add a customer" << endl << endl;

			cout << "enter a number to continue: ";
			cin >> option;

			switch (option)
			{
			case 0:
				exitProgramFlag = 0;
				break;
			case 1:
				if (userType == "A") {
					addArticle(&articles);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 2:
				if (userType == "A") {
					deleteArticle(&articles);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 3:
				if (userType == "A") {
					deleteCustomer(&customers);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 4:
				changeArticle(&articles);
				break;
			case 5:
				printInvoices(invoices);
				break;
			case 6:
				placeOrder(&invoices, customers, articles);
				break;
			case 7:
				changeCustomer(&customers);
				break;
			case 8:
				makeCustomer(&customers);
				break;

			default:
				cout << "invalid option" << endl;
				break;
			}
		}
		else {
			cout << "Not a Valid employee -> exiting" << endl;
			exitProgramFlag = 0;
		}
	}

	//clean up and close
	cout << "Shutting Down" << endl << endl;
	invoicesFilep.close();
	employeesFilep.close();
	articlesFilep.close();
	customersFilep.close();

	return 0;
}


