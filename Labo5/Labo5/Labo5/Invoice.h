#pragma once
#include <string>
#include <array>
#include "Customer.h"
#include "Article.h"

#define MAX_ARTICLES 50

class Invoice {
public:
    // Constructor
    Invoice(const Customer& customerS, const std::array<Article, MAX_ARTICLES>& articlesS, float priceS, int discountS)
        : customer(customerS), invoiceArticles(articlesS), price(priceS), discount(discountS) {}

    // Destructor
    ~Invoice() {}

    // Getters
    Customer getCustomer() const { return customer; }
    const std::array<Article, MAX_ARTICLES>& getArticles() const { return invoiceArticles; }
    float getPrice() const { return price; }
    int getDiscount() const { return discount; }

    // Setters
    void setCustomer(const Customer& customerS) { customer = customerS; }
    void setArticles(const std::array<Article, MAX_ARTICLES>& articlesS) { invoiceArticles = articlesS; }
    void setPrice(float priceS) { price = priceS; }
    void setDiscount(int discountS) { discount = discountS; }

    // Functions
    float calculateDiscount() {
        // Implement discount logic here
        return 0.0f;
    }
    float calculatePrice() {
        // Implement price calculation logic here
        return 0.0f;
    }

private:
    Customer customer;
    std::array<Article, MAX_ARTICLES> invoiceArticles;
    float price = 0;
    int discount = 0;
};