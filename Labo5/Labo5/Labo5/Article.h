#pragma once
#include <stdio.h>
#include <string>

#include "Rim.h";
#include "Tire.h";

using namespace std;

class Article : public Rim, public Tire{
public:
	// Default constructor
	Article()
		: Rim(false, "defaultColor", 0),         // Default Rim initialization
		Tire(0, 0, "defaultSpeed", 'S'),      // Default Tire initialization
		ID(0),
		name("defaultName"),
		manufacturer("defaultManufacturer"),
		stock(0),
		diameter(0),
		price(0.0f),
		type('A') {}

	// Constructor that initializes both Rim and Tire base classes
	Article(const int ID, const std::string& name, const std::string& manufacturer, int stock, int diameter, float price, char type, int tireWidth, int tireHeight, 
		const std::string& speedIndex, char season, bool aluminium, const std::string& color, int rimWidth)
		: Rim(aluminium, color, rimWidth),					// Initialize Rim base class
		Tire(tireWidth, tireHeight, speedIndex, season),	// Initialize Tire base class
		ID(ID), name(name), manufacturer(manufacturer), stock(stock), diameter(diameter), price(price), type(type) {}

	// Deconstructor
	~Article() {}

	// Getters
	int getID() const { return ID; }
	string getName() const { return name; }
	string getManufacturer() const { return manufacturer; }
	int getStock() const { return stock; }
	int getDiameter() const { return diameter; }
	float getPrice() const { return price; }
	char getType() const { return type; }

	// Setters
	void setID(const int newID) { ID = newID; }
	void setName(const string& newName) { name = newName; }
	void setManufacturer(const string& newManufacturer) { manufacturer = newManufacturer; }
	void setStock(int newStock) { stock = newStock; }
	void setDiameter(int newDiameter) { diameter = newDiameter; }
	void setPrice(float newPrice) { price = newPrice; }
	void setType(char newType) { type = newType; }


private:
	int ID;
	string name;
	string manufacturer;
	int stock;
	int diameter;
	float price;
	char type;
};