#pragma once

#include <string>
#include "Company.h"

using namespace std;

class Customer : public Company {
public:
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

private:
    int ID = 0;
    char type = ' ';
    string name = "";
    string address = "";
};