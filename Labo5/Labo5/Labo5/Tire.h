#pragma once
#include <stdio.h>
#include <string>

using namespace std;

class Tire {
public:
    // Constructor
    Tire(int widthC = 0, int heightC = 0, const string& speedIndexC = "", char seasonC = ' ') {
        tireWidth = widthC;
        tireHeight = heightC;
        speedIndex = speedIndexC;
        season = seasonC;
    }

    // Destructor
    ~Tire() {}

    // Getters
    int getWidth() const {
        return tireWidth;
    }

    int getHeight() const {
        return tireHeight;
    }

    string getSpeedIndex() const {
        return speedIndex;
    }

    char getSeason() const {
        return season;
    }

    // Setters
    void setWidth(int newWidth) {
        tireWidth = newWidth;
    }

    void setHeight(int newHeight) {
        tireHeight = newHeight;
    }

    void setSpeedIndex(const string& newSpeedIndex) {
        speedIndex = newSpeedIndex;
    }

    void setSeason(char newSeason) {
        season = newSeason;
    }
private:
	int tireWidth;
	int tireHeight;
	string speedIndex;
	char season;
};