#include "FileProcessing.h"
#include <fstream>
#include <iostream>

using namespace std;

void readArticlesFromFile(vector<Article>* articles) {
    // Open the file in input mode
    ifstream articleFileP("Articles.txt", ios::in);

    if (!articleFileP) {
        cerr << "File couldn't be opened for reading." << endl;
        exit(EXIT_FAILURE);
    }

    // Clear the vector to ensure no stale data
    articles->clear();

    // Temporary variables to hold file data
    int id, stock, diameter, tireWidth, tireHeight, rimWidth;
    float price;
    char type, season;
    bool aluminium;
    string name, manufacturer, color, speedIndex;

    // Read the file line by line
    while (articleFileP >> id >> name >> manufacturer >> stock >> diameter >> price >> type >>
        aluminium >> color >> rimWidth >> tireWidth >> tireHeight >> speedIndex >> season) {
        // Create an Article object and initialize it with the data
        Article article(id, name, manufacturer, stock, diameter, price, type,
            tireWidth, tireHeight, speedIndex, season, aluminium, color, rimWidth);

        // Add the article to the vector
        articles->push_back(article);
    }

    // Close the file
    articleFileP.close();
}

void writeArticlesToFile(vector<Article>* articles) {
	ofstream articleFileP("Articles.txt", ios::out | ios::trunc);

	if (!articleFileP) {
		cerr << "File couldn't be opened" << endl;
		exit(EXIT_FAILURE);
	}

    // Iterate through the vector and write each Article's data
    for (const auto& article : *articles) {
        articleFileP 
            << article.getID() << " "
            << article.getName() << " "
            << article.getManufacturer() << " "
            << article.getStock() << " "
            << article.getDiameter() << " "
            << article.getPrice() << " "
            << article.getType() << " "
            << article.isAluminium() << " "
            << article.getColor() << " "
            << article.getRimWidth() << " "
            << article.getWidth() << " "
            << article.getHeight() << " "
            << article.getSpeedIndex() << " "
            << article.getSeason() << endl;
    }

    // Close the file
    articleFileP.close();
}

void readCustomerFromFile(vector<Customer>* customers) {
    // Open the file in input mode
    ifstream customerFileP("Customers.txt", ios::in);

    if (!customerFileP) {
        cerr << "File couldn't be opened for reading." << endl;
        exit(EXIT_FAILURE);
    }

    // Clear the vector to remove any stale data
    customers->clear();

    // Temporary variables to hold file data
    int id, volumeDiscount;
    char type;
    string name, address, VAT;

    // Read the file line by line
    while (customerFileP >> id >> name >> address >> type >> VAT >> volumeDiscount) {
        // Create a Customer object and initialize it with the data
        Customer customer(id, name, address, type, VAT, volumeDiscount);

        // Add the customer to the vector
        customers->push_back(customer);
    }

    // Close the file
    customerFileP.close();
}

void writeCustomerToFile(vector<Customer>* customers) {
    ofstream customerFileP("Customers.txt", ios::out | ios::trunc);

    if (!customerFileP) {
        cerr << "File couldn't be opened" << endl;
        exit(EXIT_FAILURE);
    }

    // Write each Customer's data to the file
    for (const auto& customer : *customers) {
        customerFileP << customer.getID() << " "
            << customer.getName() << " "
            << customer.getAddress() << " "
            << customer.getType() << " "
            << customer.getVAT() << " "
            << customer.getVolumeDiscount() << endl;
    }

    // Close the file
    customerFileP.close();
}

void readInvoiceFromFile(vector<Invoice>* invoices) {
    // Open the file in input mode
    ifstream invoiceFileP("Invoices.txt", ios::in);

    if (!invoiceFileP) {
        cerr << "File couldn't be opened for reading." << endl;
        exit(EXIT_FAILURE);
    }

    // Clear the vector to remove any stale data
    invoices->clear();

    // Temporary variables to hold data from the file
    int customerID, volumeDiscount, articleCount, articleID, quantity;
    char customerType, articleType;
    string customerName, customerAddress, customerVAT;
    float invoicePrice, articlePrice;
    int invoiceDiscount;
    std::array<Article, MAX_ARTICLES> articles;
    std::array<int, MAX_ARTICLES> amounts;

    // Read the file line by line
    while (invoiceFileP >> customerID >> customerName >> customerAddress >> customerType >> customerVAT >> volumeDiscount
        >> invoicePrice >> invoiceDiscount >> articleCount) {
        // Read the articles and their quantities
        for (int i = 0; i < articleCount; ++i) {
            string articleName = "", manufacturer = "", speedIndex = "", color ="";
            int stock = 0, diameter = 0, tireWidth = 0, tireHeight = 0, rimWidth = 0;
            float price = 0;
            char type = ' ', season = ' ';
            bool aluminium = false;

            // Read Article data
            invoiceFileP >> articleID >> articleName >> price >> quantity;
            amounts[i] = quantity;

            // Assuming simplified Article constructor
            articles[i] = Article(articleID, articleName, manufacturer, stock, diameter, price, type,
                tireWidth, tireHeight, speedIndex, season, aluminium, color, rimWidth);
        }

        // Create Customer object
        Customer customer(customerID, customerName, customerAddress, customerType, customerVAT, volumeDiscount);

        // Create Invoice object
        Invoice invoice(customer, articles, invoicePrice, invoiceDiscount, articleCount, amounts);

        // Add the invoice to the vector
        invoices->push_back(invoice);
    }

    // Close the file
    invoiceFileP.close();
}

void writeInvoiceToFile(vector<Invoice>* invoices) {
    ofstream invoiceFileP("Invoices.txt", ios::out | ios::trunc);

    if (!invoiceFileP) {
        cerr << "File couldn't be opened" << endl;
        exit(EXIT_FAILURE);
    }

    // Write each Invoice's data to the file
    for (const auto& invoice : *invoices) {
        // Write customer details
        const Customer& customer = invoice.getCustomer();
        invoiceFileP << customer.getID() << " "
            << customer.getName() << " "
            << customer.getAddress() << " "
            << customer.getType() << " "
            << customer.getVAT() << " "
            << customer.getVolumeDiscount() << " ";

        // Write invoice details
        invoiceFileP << invoice.getPrice() << " "
            << invoice.getDiscount() << " "
            << invoice.getArticleCount() << " ";

        // Write article details
        const auto& articles = invoice.getArticles();
        const auto& amounts = invoice.getAmounts();
        for (int i = 0; i < invoice.getArticleCount(); ++i) {
            const Article& article = articles[i];
            invoiceFileP << article.getID() << " "
                << article.getName() << " "
                << article.getPrice() << " "
                << amounts[i] << " "; // Quantity
        }

        // End of this invoice's data
        invoiceFileP << endl;
    }

    // Close the file
    invoiceFileP.close();
}
