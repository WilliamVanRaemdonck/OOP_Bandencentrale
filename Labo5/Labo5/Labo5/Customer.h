#pragma once

#include <string>
#include "Company.h"
#include "TireCenterUtils.h"

using namespace std;

class Customer : public Company {
public:
    Customer()
        : Company("", 0), ID(0), name(""), address(""), type(' ') {}

    // Constructor 
    Customer(int idC, string nameC, string addressC, char typeC, string VATC, int volumeDiscountC)
        : Company(VATC, volumeDiscountC), ID(idC), name(nameC), address(addressC), type(typeC) {}

    // Destructor
    ~Customer() {}

    // Getters
    int getID() const { return ID; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    char getType() const { return type; }

    // Setters
    void setID(int idC) { ID = idC; }
    void setName(const string& nameC) { name = nameC; }
    void setAddress(const string& addressC) { address = addressC; }
    void setType(char typeC) { type = typeC; }

    // Override displayInfo function for Customer-specific information
    void displayInfo() const override {
        setTextColor(CMD_COLOR_YELLOW);
        cout << "ID: ";
        setTextColor(CMD_COLOR_WHITE);
        cout << ID << endl;

        setTextColor(CMD_COLOR_YELLOW);
        cout << "Type: ";
        setTextColor(CMD_COLOR_WHITE);
        cout << type << endl;

        setTextColor(CMD_COLOR_YELLOW);
        cout << "Name: ";
        setTextColor(CMD_COLOR_WHITE);
        cout << name << endl;

        setTextColor(CMD_COLOR_YELLOW);
        cout << "Address: ";
        setTextColor(CMD_COLOR_WHITE);
        cout << address << endl;

        Company::displayInfo();
    }

private:
    int ID = 0;
    char type = ' ';
    string name = "";
    string address = "";
};