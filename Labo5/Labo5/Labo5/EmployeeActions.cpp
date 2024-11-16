#include "EmployeeUtils.h"

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

void makeCustomer(vector<Customer> customers) {
	string newCustomerName, newCustomerAddress, newCustomerType, newCompanyVAT;
	int newCompanyVolumeDiscount;
	int highestID = 0;
	int newCustomerID;

	//prompt
	makeCustomerPrompt(&newCustomerName, &newCustomerAddress, &newCustomerType, &newCompanyVAT, &newCompanyVolumeDiscount);

	//get highest ID
	for (int i = 0; i < customers.size(); i++)
	{
		int currentHighestId = 0;
		currentHighestId = customers[i].getID();
		if (currentHighestId > highestID) {
			highestID = currentHighestId;
		}
	}

	//make and add the customer to the vector
	Customer newCustomer = { (highestID + 1), newCustomerName, newCustomerAddress, newCustomerType[0], newCompanyVAT, newCompanyVolumeDiscount };
	customers.push_back(newCustomer);

	printListOfCustomers(customers);
}

void changeCustomer(vector<Customer> customers) {
	string newCustomerName, newCustomerAddress, newCustomerType, newCompanyVAT;
	int newCompanyVolumeDiscount;
	int highestID = 0;
	int newCustomerID;
	int idToModify;

	printListOfCustomers(customers);

	cout << endl << "Enter ID from customer to modify" << endl;

	cin >> idToModify;

	//prompt
	makeCustomerPrompt(&newCustomerName, &newCustomerAddress, &newCustomerType, &newCompanyVAT, &newCompanyVolumeDiscount);

	Customer newCustomer = { idToModify, newCustomerName, newCustomerAddress, newCustomerType[0], newCompanyVAT, newCompanyVolumeDiscount };
	customers[idToModify] = newCustomer;

	printListOfCustomers(customers);
}

void deleteCustomer(vector<Customer> customers) {
	int idToModify;

	for (int i = 0; i < customers.size(); i++)
	{
		cout << customers[i].getID() << "| name: " << customers[i].getName() << endl;
	}
	cout << endl << "Enter ID from customer to delete" << endl;

	cin >> idToModify;

	customers.erase(customers.begin() + idToModify);

	cout << "customer deleted!" << endl;

	printListOfCustomers(customers);
}

//----------------


void addArticle(vector<Article> articles) {
	//article
	int newStock, newDiameter;
	char newType;
	float newPrice;
	string newName, newManufacturer;
	//tire
	int newTireWidth;
	int newTireHeight;
	string newSpeedIndex;
	char newSeason;
	//rim
	bool newAluminium;
	string newColor;
	int newRimWidth;
	//misc
	int highestID = 0;

	makeArticlePrompt(&newName, &newManufacturer, &newStock, &newDiameter, &newPrice, &newType);
	makeRimPrompt(&newAluminium, &newColor, &newRimWidth);
	makeTirePrompt(&newTireWidth, &newTireHeight, &newSpeedIndex, &newSeason);

	//get highest ID
	for (int i = 0; i < articles.size(); i++)
	{
		int currentHighestId = 0;
		currentHighestId = articles[i].getID();
		if (currentHighestId > highestID) {
			highestID = currentHighestId;
		}
	}

	//make and add the article to the vector
	Rim newRim = {newAluminium, newColor, newRimWidth};
	Tire newTire = { newTireWidth, newTireHeight, newSpeedIndex, newSeason };
	Article newArticle = { (highestID + 1), newName, newManufacturer, newStock,newDiameter, newPrice, newType, newTire.getWidth(), newTire.getHeight(), newTire.getSpeedIndex(), newTire.getSeason(), newRim.isAluminium(), newRim.getColor(), newRim.getRimWidth()};
	articles.push_back(newArticle);

	printListOfArticles(articles);
}

void changeArticle(vector<Article> articles) {
	//article
	int newStock, newDiameter;
	char newType;
	float newPrice;
	string newName, newManufacturer;
	//tire
	int newTireWidth;
	int newTireHeight;
	string newSpeedIndex;
	char newSeason;
	//rim
	bool newAluminium;
	string newColor;
	int newRimWidth;
	//misc
	int highestID = 0;
	int idToModify = 0;

	printListOfArticles(articles);

	cout << endl << "Enter ID from article to modify" << endl;
	cin >> idToModify;

	makeArticlePrompt(&newName, &newManufacturer, &newStock, &newDiameter, &newPrice, &newType);
	makeRimPrompt(&newAluminium, &newColor, &newRimWidth);
	makeTirePrompt(&newTireWidth, &newTireHeight, &newSpeedIndex, &newSeason);

	//make and add the article to the vector
	Rim newRim = { newAluminium, newColor, newRimWidth };
	Tire newTire = { newTireWidth, newTireHeight, newSpeedIndex, newSeason };
	Article newArticle = {idToModify, newName, newManufacturer, newStock,newDiameter, newPrice, newType, newTire.getWidth(), newTire.getHeight(), newTire.getSpeedIndex(), newTire.getSeason(), newRim.isAluminium(), newRim.getColor(), newRim.getRimWidth() };
	articles[idToModify] = newArticle;

	printListOfArticles(articles);
}

void deleteArticle(vector<Article> articles) {
	int idToDelete;

	for (int i = 0; i < articles.size(); i++)
	{
		cout << articles[i].getID() << "| name: " << articles[i].getName() << endl;
	}
	cout << endl << "Enter ID from article to delete" << endl;

	cin >> idToDelete;

	articles.erase(articles.begin() + idToDelete);

	cout << "article deleted!" << endl;

	printListOfArticles(articles);
}

//----------------

void printListOfCustomers(vector<Customer> customers) {
	if (customers.empty()) {
		setTextColor(CMD_COLOR_RED);
		cout << "No customers available." << std::endl;
		setTextColor(CMD_COLOR_WHITE);
		return;
	}

	cout << "================ List of Customers ================" << endl;

	for (const auto& customer : customers) {
		setTextColor(CMD_COLOR_YELLOW);
		cout << "ID: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customer.getID() << endl;
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Type: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customer.getType() << endl;
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Name: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customer.getName() << endl;
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Address: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << customer.getAddress() << endl;
		cout << "--------------------------------------------------" << endl;
	}

	cout << "==================================================" << endl << endl;
}

void printListOfArticles(vector<Article> articles) {
	if (articles.empty()) {
		setTextColor(CMD_COLOR_RED);
		cout << "No articles available." << std::endl;
		setTextColor(CMD_COLOR_WHITE);
		return;
	}

	cout << endl << "New List of Articles" << endl;

	for (const auto& article : articles) {
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

