#pragma once
#include <stdio.h>
#include <string>

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
	string getVAT() {
		return VAT;
	}
	int getVolumeDiscount() {
		return volumeDiscount;
	}

	//Setters
	void setVAT(string VATS) {
		VAT = VATS;
	}
	void setVolumeDiscount(int volumeDiscountS) {
		volumeDiscount = volumeDiscountS;
	}

private:
	string VAT = "";
	int volumeDiscount = 0;
};