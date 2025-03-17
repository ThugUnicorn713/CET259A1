#include "Rectangle.h"
#include "SaveManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Rectangle::RectAsk() {

	do {
		cout << "Please Enter the Height and Width of your Rectangle (2 - 50)" << endl;
		cout << "Height: "; cin >> height;
		cout << "Width: "; cin >> width;

		if (height < 2 || height > 50 || width < 2 || width > 50) {
			cout << " Sorry that input was invalid. Please enter values between 2 and 50." << endl; //validation is weird
		}
	} while (height <= 2 && height >= 50 && width <= 2 && width >= 50);

	
	DrawRectangle(height, width);
	SaveAsk();
}

void Rectangle::DrawRectangle(int height, int width) {

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			cout << setw(3) << "*";
		}

		cout << endl;

	}
	
}

void Rectangle::AskSymbol() {

	cout << " Would you like to draw a Rectangle in one of these symbols? ( & , # , + ) ";
	cin >> userSymbol;
	SymbolSwitch(userSymbol);
}

void Rectangle::SaveAsk() {

	SaveManager sm;

	while (true) {

		cout << "Would you like to save this shape? (Y/N)" << endl;
		cin >> saveAnswer;

		if (saveAnswer == "Y" || saveAnswer == "y") {

			int id;

			cout << "Please Enter ID for this Triangle: ";
			cin >> id;


			sm.SaveShape(id, "Rectangle", height, width);
			sm.SaveToFile();
			break;

		}
		else if (saveAnswer == "N" || saveAnswer == "n") {

			AskSymbol();
			break;
		}
		else {
			cout << "Please Enter Y for Yes or N for No." << endl;
		}

	}

}

void Rectangle::SymbolSwitch(char symbol) {

	if (symbol == '&' || symbol == '#' || symbol == '+') {

		switch (symbol)
		{
		case '&':
		{
			DrawandRectangle();
			break;
		}

		case '#':
		{
			DrawpoundRectangle();
			break;
		}

		case '+':
		{
			DrawplusRectangle();
			break;
		}

		}
	}
	else {
		cout << "Please submit a valid symbol ( & , # , + ), Please try Again...\n";
		AskSymbol();
	}
}

void Rectangle::DrawandRectangle() {

	do {
		cout << "Please input the number height and width of your Rectangle (5 - 50) :" << endl;
		cout << "Height: "; cin >> symHeight;
		cout << "Width: "; cin >> symWidth;

	} while (symHeight <= 2 && symHeight >= 50 && symWidth <= 2 && symWidth >= 50);

	for (int i = 0; i < symHeight; i++) {

		for (int j = 0; j < symWidth; j++) {
			cout << setw(3) << "&";
		}

		cout << endl;

	}
}

void Rectangle::DrawpoundRectangle() {

	do {
		cout << "Please input the number height and width of your Rectangle (5 - 50) :" << endl;
		cout << "Height: "; cin >> symHeight;
		cout << "Width: "; cin >> symWidth;

	} while (symHeight <= 2 && symHeight >= 50 && symWidth <= 2 && symWidth >= 50);

	for (int i = 0; i < symHeight; i++) {

		for (int j = 0; j < symWidth; j++) {
			cout << setw(3) << "#";
		}

		cout << endl;

	}
}

void Rectangle::DrawplusRectangle() {

	do {
		cout << "Please input the number height and width of your Rectangle (5 - 50) :" << endl;
		cout << "Height: "; cin >> symHeight;
		cout << "Width: "; cin >> symWidth;

	} while (symHeight <= 2 && symHeight >= 50 && symWidth <= 2 && symWidth >= 50);

	for (int i = 0; i < symHeight; i++) {

		for (int j = 0; j < symWidth; j++) {
			cout << setw(3) << "+";
		}

		cout << endl;

	}
}
