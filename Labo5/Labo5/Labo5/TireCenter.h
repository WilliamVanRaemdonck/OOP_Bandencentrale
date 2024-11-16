#pragma once

#include <stdio.h>
#include <string>
#include <vector>

#include "Article.h"
#include "Customer.h"
#include "Invoice.h"

#define MAX_ARTICLES 50
#define MAX_CUSTOMERS 50
#define MAX_INVOICES 50

using namespace std;

class TireCenter {
public:
	// Constructor
	TireCenter(const std::string& name, const std::string& address)
		: name(name), address(address) {};

	// Destructor
	~TireCenter() {   }

	// Setters
	void setName(const string& nameS) {
		name = nameS;
	}
	void setAddress(const string& addressS) {
		address = addressS;
	}

	// Getters
	string getName() const { return name; }
	string getAddress() const { return address; }

	// Add methods to manage articles, customers, and invoices
	void addArticle(const Article& article) {
		articles.push_back(article);
	}

	void addCustomer(const Customer& customer) {
		customers.push_back(customer);
	}

	void addInvoice(const Invoice& invoice) {
		invoices.push_back(invoice);
	}

	// Get articles, customers, and invoices
	const vector<Article>& getArticles() const { return articles; }
	const vector<Customer>& getCustomers() const { return customers; }
	const vector<Invoice>& getInvoices() const { return invoices; }

private:
	string name = "";
	string address = "";
	vector<Article> articles;		// Composition with vector for dynamic handling
	vector<Customer> customers;		// Composition with vector
	vector<Invoice> invoices;		// Composition with vector
};