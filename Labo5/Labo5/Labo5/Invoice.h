#pragma once
#include <string>
#include <array>
#include "Customer.h"
#include "Article.h"

#define MAX_ARTICLES 50

class Invoice {
public:
    // Constructor
    Invoice(const Customer& customerS, const std::array<Article, MAX_ARTICLES>& articlesS, float priceS, int discountS, int articleCountS, const std::array<int, MAX_ARTICLES>& pricesS)
        : customer(customerS), invoiceArticles(articlesS), price(priceS), discount(discountS), articleCount(articleCountS), prices(pricesS) {}

    // Destructor
    ~Invoice() {}

    // Getters
    Customer getCustomer() const { return customer; }
    const std::array<Article, MAX_ARTICLES>& getArticles() const { return invoiceArticles; }
    float getPrice() const { return price; }
    int getDiscount() const { return discount; }
    int setArticleCount() const { return articleCount; }

    // Setters
    void setCustomer(const Customer& customerS) { customer = customerS; }
    void setArticles(const std::array<Article, MAX_ARTICLES>& articlesS) { invoiceArticles = articlesS; }
    void setPrice(float priceS) { price = priceS; }
    void setDiscount(int discountS) { discount = discountS; }
    int getArticleCount() const { return articleCount; }

    // Functions
    float calculateDiscount() {
        price = price - (price * (discount / 100));
        return price;
    }

    float calculatePrice() {
        price = 0;
        for (int i = 0; i < invoiceArticles.size(); i++)
        {
            price += invoiceArticles[i].getPrice() * prices[i];// dees moet me aantallen zijn denk ik
        }
        return price;
    }

private:
    Customer customer;
    std::array<Article, MAX_ARTICLES> invoiceArticles;
    std::array<int, MAX_ARTICLES> prices;
    float price = 0;
    int discount = 0;
    int articleCount;
};