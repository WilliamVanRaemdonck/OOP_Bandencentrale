#pragma once
#include <string>
#include <array>
#include "Customer.h"
#include "Article.h"

#define MAX_ARTICLES 50

class Invoice {
public:
    // Default Constructor
    Invoice()
        : customer(Customer()),
        invoiceArticles(),
        price(0.0f),
        discount(0),
        articleCount(0),
        amounts() {}

    // Constructor
    Invoice(const Customer& customerS, const std::array<Article, MAX_ARTICLES>& articlesS, float priceS, int discountS, int articleCountS, const std::array<int, MAX_ARTICLES>& amountsS)
        : customer(customerS), invoiceArticles(articlesS), price(priceS), discount(discountS), articleCount(articleCountS), amounts(amountsS) {}

    // Destructor
    ~Invoice() {}

    // Getters
    Customer getCustomer() const { return customer; }
    const std::array<Article, MAX_ARTICLES>& getArticles() const { return invoiceArticles; }
    float getPrice() const { return price; }
    int getDiscount() const { return discount; }
    int getArticleCount() const { return articleCount; }
    const std::array<int, MAX_ARTICLES>& getAmounts() const { return amounts; }


    // Setters
    void setCustomer(const Customer& customerS) { customer = customerS; }
    void setArticles(const std::array<Article, MAX_ARTICLES>& articlesS) { invoiceArticles = articlesS; }
    void setPrice(float priceS) { price = priceS; }
    void setDiscount(int discountS) { discount = discountS; }
    void setArticleCount(int ArticleCountS) { articleCount = ArticleCountS; }
    void setAmounts(const std::array<int, MAX_ARTICLES>& newAmounts) { amounts = newAmounts; }

    // Functions
    float calculateDiscount() {
        float discountedPrice = 0;
        float discountStep = 0;
        float discountPercent = (float)discount / 100;
        discountedPrice = (price - (price * discountPercent));
        return discountedPrice;
    }

    float calculatePrice() {
        price = 0;
        for (int i = 0; i < invoiceArticles.size(); i++)
        {
            price += invoiceArticles[i].getPrice() * amounts[i];
        }
        return price;
    }

private:
    Customer customer;
    std::array<Article, MAX_ARTICLES> invoiceArticles;
    std::array<int, MAX_ARTICLES> amounts;
    float price = 0;
    int discount = 0;
    int articleCount;
};