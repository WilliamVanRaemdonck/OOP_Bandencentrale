#include "TireCenterUtils.h"

// Function to change text color
void setTextColor(int colorCode) {
	std::cout << "\033[1;" << colorCode << "m";  // ANSI escape sequence
}