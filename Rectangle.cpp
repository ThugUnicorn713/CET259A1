#include "Rectangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

void RectAsk();
void DrawRectangle(int height, int width);

class Rectangle {

	void RectAsk();
};

void RectAsk() {

	int height;
	int width;

	do {
		cout << "Please Enter the Height and Width of your Rectangle (2 - 50)" << endl;
		cout << "Height: "; cin >> height;
		cout << "Width: "; cin >> width;

		if (height < 2 || height > 50 || width < 2 || width > 50) {
			cout << " Sorry that input was invalid. Please enter values between 2 and 50." << endl; //validation is weird
		}
	} while (height <= 2 && height >= 50 && width <= 2 && width >= 50);

	
	DrawRectangle(height, width);
	
}

void DrawRectangle(int height, int width) {

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			cout << setw(3) << "*";
		}

		cout << endl;

	}
}