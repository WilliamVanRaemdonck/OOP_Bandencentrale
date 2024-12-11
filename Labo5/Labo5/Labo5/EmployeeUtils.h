#pragma once

#include <iostream>
#include <string.h>
#include <vector>

#include "Customer.h"
#include "Article.h"
#include "Invoice.h"
#include "TireCenterUtils.h"

void makeCustomerPrompt(string*, string*, string*, string*, int*);
void makeArticlePrompt(string*, string*, int*, int*, float*, char*);
void makeRimPrompt(bool*, string*, int*);
void makeTirePrompt(int*, int*, string*, char*);

void makeCustomer(vector<Customer>*);
void changeCustomer(vector<Customer>*);
void deleteCustomer(vector<Customer>*);

void printListOfCustomers(vector<Customer>*);
void printListOfArticles(vector<Article>*);

void addArticle(vector<Article>*);
void changeArticle(vector<Article>*);
void deleteArticle(vector<Article>*);

void printInvoices(vector<Invoice>);
void placeOrder(vector<Invoice>*, vector<Customer>, vector<Article>);
int updateStock(vector<Article>* ,string, int);
