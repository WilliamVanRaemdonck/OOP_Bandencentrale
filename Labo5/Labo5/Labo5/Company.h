#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "TireCenterUtils.h"

using namespace std;

class Company {
public:
	// Constructor 
	Company(string VATC = "", int volumeDiscountC = 0) {
		VAT = VATC;
		volumeDiscount = volumeDiscountC;
	}

	// Destructor
	~Company() {}

	//getters
	string getVAT() const{
		return VAT;
	}
	int getVolumeDiscount() const {
		return volumeDiscount;
	}

	//Setters
	void setVAT(string VATS) {
		VAT = VATS;
	}
	void setVolumeDiscount(int volumeDiscountS) {
		volumeDiscount = volumeDiscountS;
	}

	// Virtual function for polymorphism
	virtual void displayInfo() const {
		setTextColor(CMD_COLOR_YELLOW);
		cout << "Company VAT: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << VAT << endl;

		setTextColor(CMD_COLOR_YELLOW);
		cout << "Volume Discount: ";
		setTextColor(CMD_COLOR_WHITE);
		cout << volumeDiscount << "%" << endl;
	}

private:
	string VAT = "";
	int volumeDiscount = 0;
};