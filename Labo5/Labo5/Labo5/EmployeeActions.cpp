#include "EmployeeUtils.h"
#include "FileProcessing.h"
#include "Invoice.h"
#include "Customer.h"
#include "string.h"
#include <fstream>
#include <iostream>

using namespace std;

void makeCustomerPrompt(string* newCustomerName, string* newCustomerAddress, string* newCustomerType, string* newCompanyVAT, int* newCompanyVolumeDiscount) {
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new customer name: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newCustomerName;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new customer address: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newCustomerAddress;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new customer type: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newCustomerType;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter customer company VAT: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newCompanyVAT;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter customer company volume discount: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newCompanyVolumeDiscount;
}

void makeArticlePrompt(string* newName, string* newManufacturer, int* newStock, int* newDiameter, float* newPrice, char* newType) {
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article name: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newName;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article manufacturer: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newManufacturer;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article stock: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newStock;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article diameter: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newDiameter;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article price: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newPrice;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter new article type: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *newType;
}

void makeTirePrompt(int* tireWidth, int* tireHeight, string* speedIndex, char* season) {
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter tire width: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *tireWidth;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter tire height: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *tireHeight;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter tire speed index: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *speedIndex;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter tire season (e.g., W for Winter, S for Summer): ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *season;
}

void makeRimPrompt(bool* aluminium, string* color, int* rimWidth) {
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Is the rim made of aluminium? (1 for Yes, 0 for No): ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *aluminium;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter rim color: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *color;

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Enter rim width: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> *rimWidth;
}

//----------------

void makeCustomer(vector<Customer>* customers) {
	string newCustomerName, newCustomerAddress, newCustomerType, newCompanyVAT;
	int newCompanyVolumeDiscount;
	int highestID = 0;

	// Prompt for customer details
	makeCustomerPrompt(&newCustomerName, &newCustomerAddress, &newCustomerType, &newCompanyVAT, &newCompanyVolumeDiscount);

	// Get highest ID
	for (int i = 0; i < customers->size(); i++) {
		int currentHighestId = customers->at(i).getID();
		if (currentHighestId > highestID) {
			highestID = currentHighestId;
		}
	}

	// Dynamically allocate memory for a new Customer
	Customer* newCustomer = new Customer(highestID + 1, newCustomerName, newCustomerAddress,
		newCustomerType[0], newCompanyVAT, newCompanyVolumeDiscount);

	// Add the dynamically created Customer to the vector
	customers->push_back(*newCustomer);

	// Clean up dynamically allocated memory
	delete newCustomer;

	// Display the list of customers and write to file
	printListOfCustomers(customers);
	writeCustomerToFile(customers);
}

void changeCustomer(vector<Customer>* customers) {
	string newCustomerName, newCustomerAddress, newCustomerType, newCompanyVAT;
	int newCompanyVolumeDiscount;
	int idToModify;

	// Print list of customers
	printListOfCustomers(customers);

	// Get the ID of the customer to modify
	cout << endl << "Enter ID from customer to modify: ";
	cin >> idToModify;

	// Prompt for new customer details
	makeCustomerPrompt(&newCustomerName, &newCustomerAddress, &newCustomerType, &newCompanyVAT, &newCompanyVolumeDiscount);

	// Dynamically allocate a new Customer
	Customer* newCustomer = new Customer(idToModify, newCustomerName, newCustomerAddress,
		newCustomerType[0], newCompanyVAT, newCompanyVolumeDiscount);

	// Replace the customer in the vector with the new customer
	customers->at(idToModify) = *newCustomer;

	// Clean up dynamically allocated memory
	delete newCustomer;

	// Print updated list of customers and write to file
	printListOfCustomers(customers);
	writeCustomerToFile(customers);
}

void deleteCustomer(vector<Customer>* customers) {
	int idToModify;

	for (int i = 0; i < customers->size(); i++)
	{
		cout << customers->at(i).getID() << "| name: " << customers->at(i).getName() << endl;
	}
	cout << endl << "Enter ID from customer to delete" << endl;

	cin >> idToModify;

	customers->erase(customers->begin() + idToModify);

	cout << "customer deleted!" << endl;

	printListOfCustomers(customers);

	writeCustomerToFile(customers);
}

//----------------

void addArticle(vector<Article>* articles) {
	// Article details
	int newStock, newDiameter;
	char newType;
	float newPrice;
	string newName, newManufacturer;

	// Tire details
	int newTireWidth;
	int newTireHeight;
	string newSpeedIndex;
	char newSeason;

	// Rim details
	bool newAluminium;
	string newColor;
	int newRimWidth;

	// Misc
	int highestID = 0;

	// Prompt user for details
	makeArticlePrompt(&newName, &newManufacturer, &newStock, &newDiameter, &newPrice, &newType);
	makeRimPrompt(&newAluminium, &newColor, &newRimWidth);
	makeTirePrompt(&newTireWidth, &newTireHeight, &newSpeedIndex, &newSeason);

	// Get highest ID
	for (int i = 0; i < articles->size(); i++) {
		int currentHighestId = articles->at(i).getID();
		if (currentHighestId > highestID) {
			highestID = currentHighestId;
		}
	}

	// Dynamically allocate Rim and Tire
	Rim* newRim = new Rim(newAluminium, newColor, newRimWidth);
	Tire* newTire = new Tire(newTireWidth, newTireHeight, newSpeedIndex, newSeason);

	// Dynamically allocate Article
	Article* newArticle = new Article(highestID + 1, newName, newManufacturer, newStock, newDiameter,
		newPrice, newType, newTire->getWidth(), newTire->getHeight(),
		newTire->getSpeedIndex(), newTire->getSeason(),
		newRim->isAluminium(), newRim->getColor(), newRim->getRimWidth());

	// Add the Article to the vector
	articles->push_back(*newArticle);

	// Clean up dynamically allocated Rim, Tire, and Article
	delete newRim;
	delete newTire;
	delete newArticle;

	// Display updated list and write to file
	printListOfArticles(articles);
	writeArticlesToFile(articles);
}

void changeArticle(vector<Article>* articles) {
	// Article details
	int newStock, newDiameter;
	char newType;
	float newPrice;
	string newName, newManufacturer;

	// Tire details
	int newTireWidth;
	int newTireHeight;
	string newSpeedIndex;
	char newSeason;

	// Rim details
	bool newAluminium;
	string newColor;
	int newRimWidth;

	// Misc
	int idToModify = 0;

	// Print list of articles
	printListOfArticles(articles);

	// Prompt user for ID to modify
	cout << endl << "Enter ID from article to modify: ";
	cin >> idToModify;

	// Prompt user for new details
	makeArticlePrompt(&newName, &newManufacturer, &newStock, &newDiameter, &newPrice, &newType);
	makeRimPrompt(&newAluminium, &newColor, &newRimWidth);
	makeTirePrompt(&newTireWidth, &newTireHeight, &newSpeedIndex, &newSeason);

	// Dynamically allocate Rim and Tire
	Rim* newRim = new Rim(newAluminium, newColor, newRimWidth);
	Tire* newTire = new Tire(newTireWidth, newTireHeight, newSpeedIndex, newSeason);

	// Dynamically allocate Article
	Article* newArticle = new Article(idToModify, newName, newManufacturer, newStock, newDiameter,
		newPrice, newType, newTire->getWidth(), newTire->getHeight(),
		newTire->getSpeedIndex(), newTire->getSeason(),
		newRim->isAluminium(), newRim->getColor(), newRim->getRimWidth());

	// Replace the existing Article in the vector
	articles->at(idToModify) = *newArticle;

	// Clean up dynamically allocated Rim, Tire, and Article
	delete newRim;
	delete newTire;
	delete newArticle;

	// Display updated list and write to file
	printListOfArticles(articles);
	writeArticlesToFile(articles);
}

void deleteArticle(vector<Article>* articles) {
	int idToDelete;

	for (int i = 0; i < articles->size(); i++)
	{
		cout << articles->at(i).getID() << "| name: " << articles->at(i).getName() << endl;
	}
	cout << endl << "Enter ID from article to delete" << endl;

	cin >> idToDelete;

	articles->erase(articles->begin() + idToDelete);

	cout << "article deleted!" << endl;

	printListOfArticles(articles);

	writeArticlesToFile(articles);
}

//----------------

void printListOfCustomers(vector<Customer>* customers) {
	if (customers->empty()) {
		setTextColor(CMD_COLOR_RED);
		cout << "No customers available." << std::endl;
		setTextColor(CMD_COLOR_WHITE);
		return;
	}

	cout << "================ List of Customers ================" << endl;

	for (const auto& customer : *customers) {
		// Call the displayInfo function from the Customer class
		customer.displayInfo();  // This will call Customer's overridden displayInfo()
		cout << "--------------------------------------------------" << endl;
	}

	cout << "==================================================" << endl << endl;
}

void printListOfArticles(vector<Article>* articles) {
	if (articles->empty()) {
		setTextColor(CMD_COLOR_RED);
		cout << "No articles available." << std::endl;
		setTextColor(CMD_COLOR_WHITE);
		return;
	}

	cout << endl << "New List of Articles" << endl;

	for (const auto& article : *articles) {
		setTextColor(CMD_COLOR_YELLOW);
		cout << "ID: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getID() << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Name: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getName() << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Manufacturer: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getManufacturer() << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Stock: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getStock() << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Diameter: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getDiameter() << " mm" << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Price: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getPrice() << " EURO" << "\t|\t";

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Type: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << article.getType() << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Tire Details:" << endl;
		setTextColor(CMD_COLOR_WHITE);
		cout << "  - Width: " << article.getWidth() << " mm" << endl;
		cout << "  - Height: " << article.getHeight() << " mm" << endl;
		cout << "  - Speed Index: " << article.getSpeedIndex() << endl;
		cout << "  - Season: " << article.getSeason() << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Rim Details:" << endl;
		setTextColor(CMD_COLOR_WHITE);
		cout << "  - Aluminium: " << (article.isAluminium() ? "Yes" : "No") << endl;
		cout << "  - Color: " << article.getColor() << endl;
		cout << "  - Width: " << article.getRimWidth() << " mm" << endl;

		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}

	cout << endl << endl;
}

void printInvoices(vector<Invoice> invoices) {
	float totalprice = 0;

	if (invoices.empty()) {
		setTextColor(CMD_COLOR_RED);
		cout << endl << "================ No Invoices Available ================" << endl;
		setTextColor(CMD_COLOR_WHITE);
		return;
	}

	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "===================== List of Invoices =====================" << endl;

	for (auto& invoice : invoices) {
		// Customer details
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Customer Name: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << invoice.getCustomer().getName() << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Customer Address: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << invoice.getCustomer().getAddress() << endl;

		// Discount
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Discount: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << invoice.getDiscount() << "%" << endl;

		// Articles
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Articles Ordered: " << endl;
		setTextColor(CMD_COLOR_WHITE);

		auto& articles = invoice.getArticles();
		auto& amounts = invoice.getAmounts();

		for (size_t i = 0; i < invoice.getArticleCount(); ++i) {
			setTextColor(CMD_COLOR_WHITE);
			cout << "  - ";
			setTextColor(CMD_COLOR_CYAN);
			cout << amounts[i] << "x ";
			setTextColor(CMD_COLOR_WHITE);
			cout << articles[i].getName();
			setTextColor(CMD_COLOR_YELLOW);
			cout << " (ID: ";
			setTextColor(CMD_COLOR_WHITE);
			cout << articles[i].getID();
			setTextColor(CMD_COLOR_YELLOW);
			cout << ")" << endl;
		}
		cout << endl;

		// Total price
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Total Price (before discount): ";
		setTextColor(CMD_COLOR_WHITE);

		totalprice = invoice.calculatePrice();
		cout << totalprice << " EUR" << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Total Price (after discount): ";
		setTextColor(CMD_COLOR_WHITE);

		totalprice = invoice.calculateDiscount();
		cout << totalprice << " EUR" << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "------------------------------------------------------------" << endl;
	}

	setTextColor(CMD_COLOR_CYAN);
	cout << "============================================================" << endl << endl;
}

void placeOrder(vector<Invoice>* invoices, vector<Customer> customers, vector<Article> articles) {
	Customer* newCustomer = nullptr;
	Invoice* newInvoice = nullptr;
	auto* newInvoiceArticles = new std::array<Article, MAX_ARTICLES>;
	auto* newAmounts = new std::array<int, MAX_ARTICLES>;
	float newPrice = 0;
	int newDiscount = 0;
	int newArticleCount = 0;

	// Function variables
	int invoiceID = 0;
	string nextIDToAdd = "0";
	int newAmountToAdd = 0;

	// Display customers
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "================ List of Available Customers ================" << endl;
	for (int i = 0; i < customers.size(); i++) {
		setTextColor(CMD_COLOR_YELLOW);
		cout << "ID: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customers[i].getID() << " ";
		setTextColor(CMD_COLOR_YELLOW);
		cout << "NAME: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customers[i].getName() << endl;
	}
	setTextColor(CMD_COLOR_CYAN);
	cout << "============================================================" << endl;
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "Select a customer ID for the order: ";
	setTextColor(CMD_COLOR_WHITE);
	cin >> invoiceID;

	// Find customer for order
	for (int i = 0; i < customers.size(); i++) {
		if (invoiceID == customers[i].getID()) {
			newCustomer = new Customer(customers[i]);
			break; // Exit loop once customer is found
		}
	}

	// Check if customer was found
	if (!newCustomer) {
		setTextColor(CMD_COLOR_RED);
		cout << "Error: Customer with the given ID not found!" << endl;
		setTextColor(CMD_COLOR_WHITE);
		delete newInvoiceArticles;
		delete newAmounts;
		return;
	}

	// Add articles to the invoice
	setTextColor(CMD_COLOR_CYAN);
	cout << endl << "================ List of Available Articles ================" << endl;
	cout << "(Enter \"exit\" to stop adding articles)" << endl;

	int index = 0;
	while (nextIDToAdd != "exit") {
		// Display articles
		for (int i = 0; i < articles.size(); i++) {
			setTextColor(CMD_COLOR_YELLOW);
			cout << "ID: ";
			setTextColor(CMD_COLOR_WHITE);
			cout << articles[i].getID() << " ";
			setTextColor(CMD_COLOR_YELLOW);
			cout << "NAME: ";
			setTextColor(CMD_COLOR_WHITE);
			cout << articles[i].getName() << endl;
		}
		setTextColor(CMD_COLOR_CYAN);
		cout << endl << "Enter Article ID or exit: ";
		setTextColor(CMD_COLOR_WHITE);
		cin >> nextIDToAdd;

		if (nextIDToAdd != "exit") {
			setTextColor(CMD_COLOR_CYAN);
			cout << "Enter Quantity: ";
			setTextColor(CMD_COLOR_WHITE);
			cin >> newAmountToAdd;

			//update stock
			int err = updateStock(&articles, nextIDToAdd, newAmountToAdd);
			if (err != 0) {
				cout << "Error not enougf stock available for this item" << endl;
			}
			else {
				writeArticlesToFile(&articles);

				Article* articleToAdd = nullptr;
				// Find article and add it to the invoice
				for (int i = 0; i < articles.size(); i++) {
					if (nextIDToAdd == std::to_string(articles[i].getID())) {
						articleToAdd = new Article(articles[i]);
						break; // Exit loop once article is found
					}
				}

				if (!articleToAdd) {
					setTextColor(CMD_COLOR_RED);
					cout << "Error: Article with the given ID not found!" << endl;
					setTextColor(CMD_COLOR_WHITE);
					continue;
				}

				(*newInvoiceArticles)[index] = *articleToAdd;
				(*newAmounts)[index] = newAmountToAdd;
				index++;

				// Update price
				newPrice += (newAmountToAdd * articleToAdd->getPrice());
				newArticleCount++;

				// Clean up dynamically allocated Article
				delete articleToAdd;
			}
			
		}
	}

	// Apply discount from customer
	newDiscount = newCustomer->getVolumeDiscount();

	// Create the new invoice dynamically
	newInvoice = new Invoice(*newCustomer, *newInvoiceArticles, newPrice, newDiscount, newArticleCount, *newAmounts);

	// Add the invoice to the vector
	invoices->push_back(*newInvoice);

	// Clean up dynamically allocated memory
	delete newCustomer;
	delete newInvoice;
	delete newInvoiceArticles;
	delete newAmounts;

	// Final confirmation
	setTextColor(CMD_COLOR_GREEN);
	cout << endl << "Order placed successfully! Invoice has been created." << endl;
	setTextColor(CMD_COLOR_WHITE);

	writeInvoiceToFile(invoices);
}

int updateStock(vector<Article>* articles, string ID, int amount) {
	// Find the article with the given ID
	for (auto& article : *articles) {
		if (to_string(article.getID()) == ID) {
			// Check if there is sufficient stock
			if (amount > 0 && article.getStock() < amount) {
				// Not enough stock for the order
				return -1; // Error code for insufficient stock
			}
			// Update stock (decrease for orders, increase for restocking)
			article.setStock(article.getStock() - amount);
			setTextColor(CMD_COLOR_CYAN);
			cout << "Stock updated successfully for Article ID " << ID << ". New stock: " << article.getStock() << endl;
			setTextColor(CMD_COLOR_WHITE);
			return 0; // Success
		}
	}

	// If the article was not found
	return -2; // Error code for article not found
}
