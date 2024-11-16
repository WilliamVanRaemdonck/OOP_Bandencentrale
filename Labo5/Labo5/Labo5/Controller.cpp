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

	//Maak test objecten aan
	Rim rim1 = {false, "black", 10};
	Tire tire1 = {10, 10, "120", 'Z'};
	Article article1 = {0,"article1", "fabricakant1", 100, 10, 50, 'Z', tire1.getWidth(), tire1.getHeight(), tire1.getSpeedIndex(), tire1.getSeason(), rim1.isAluminium(), rim1.getColor(), rim1.getRimWidth()};
	Rim rim2 = { false, "black", 10 };
	Tire tire2 = { 10, 10, "120", 'Z' };
	Article article2 = {1, "article2", "fabricakant1", 100, 10, 50, 'Z', tire2.getWidth(), tire2.getHeight(), tire2.getSpeedIndex(), tire2.getSeason(), rim2.isAluminium(), rim2.getColor(), rim2.getRimWidth() };

	Customer customer1 = { 0, "bob1", "straat1", 'C', "VAT123", 10 };
	Customer customer2 = { 1, "bob2", "straat2", 'C', "VAT123", 10 };

	array<Article, MAX_ARTICLES> articlesCustomer1 = {article1};
	array<Article, MAX_ARTICLES> articlesCustomer2 = {article2};
	array<int, MAX_ARTICLES> prices1 = { 15 };
	array<int, MAX_ARTICLES> prices2 = { 20 };
	Invoice invoice1 = {customer1, articlesCustomer1 , 50, 10, 1, prices1};
	Invoice invoice2 = { customer2, articlesCustomer2 , 50, 10, 1 , prices2};

	articles.push_back(article1);
	articles.push_back(article2);
	customers.push_back(customer1);
	customers.push_back(customer2);
	invoices.push_back(invoice1);
	invoices.push_back(invoice2);

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
					addArticle(articles);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 2:
				if (userType == "A") {
					deleteArticle(articles);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 3:
				if (userType == "A") {
					deleteCustomer(customers);
				}
				else {
					cout << "option not available: not an admin" << endl;
				}
				break;
			case 4:
				changeArticle(articles);
				break;
			case 5:
				printInvoices(invoices);
				break;
			case 6:
				placeOrder(invoices);
				break;
			case 7:
				changeCustomer(customers);
				break;
			case 8:
				makeCustomer(customers);
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
	employeesFilep.close();
	articlesFilep.close();
	customersFilep.close();

	return 0;
}


