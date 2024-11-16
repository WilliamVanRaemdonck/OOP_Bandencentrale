#pragma once
#include <stdio.h>
#include <string>

using namespace std;

class Rim {
public:
    // Constructor
    Rim(bool aluminiumC = false, const string& colorC = "", int widthC = 0) {
        aluminium = aluminiumC;
        color = colorC;
        rimWidth = widthC;
    }

    // Destructor
    ~Rim() {}

    // Getters
    bool isAluminium() const {
        return aluminium;
    }
    string getColor() const {
        return color;
    }
    int getRimWidth() const {
        return rimWidth;
    }

    // Setters
    void setAluminium(bool AluminiumS) {
        aluminium = AluminiumS;
    }
    void setColor(const string& ColorS) {
        color = ColorS;
    }
    void setWidth(int WidthS) {
        rimWidth = WidthS;
    }

private:
	bool aluminium;
	string color;
	int rimWidth;
};