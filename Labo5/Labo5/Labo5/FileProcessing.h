#pragma once
#include "Article.h"
#include "Customer.h"
#include "Invoice.h"
#include <vector>

void readArticlesFromFile(vector<Article>*);
void writeArticlesToFile(vector<Article>*);

void readCustomerFromFile(vector<Customer>*);
void writeCustomerToFile(vector<Customer>*);

void readInvoiceFromFile(vector<Invoice>*);
void writeInvoiceToFile(vector<Invoice>*);