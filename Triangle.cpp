#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle(int h) {
	userNum = h;  //might work or maybe try height
}

void Triangle::TriAsk() {

	do {
		cout << "Please input the number height of your Triangle (5 - 50) :";
		cin >> userNum;

	} while (userNum >= 50 && userNum <= 5); // add validation 


	DrawTriangle(userNum);


}

void Triangle::SaveAsk() {
	
	while (true) {

		cout << "Would you like to save this shape? (Y/N)" << endl;
		cin >> saveAnswer;

		if (saveAnswer == "Y" || saveAnswer == "y") {
			SaveTriangle(); // save from save manager
		}
		else if (saveAnswer == "N" || saveAnswer == "n") {

			AskSymbol();
		}
		else {
			cout << "Please Enter Y for yes or N for no." << endl;
		}

	}
}

void Triangle::AskSymbol() {

	cout << " Would you like to draw this Triangle in one of these symbols? ( & , # , + ) ";
	cin >> userSymbol;
	SymbolSwitch(userSymbol);
}

void Triangle::DrawTriangle(int height) {

	for (int i = 0; i < height + 1; i++) {

		for (int j = 0; j < height - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < i; k++) {
			cout << "* ";
		}

		cout << endl;
	}
	
}

void Triangle::SymbolSwitch(char symbol) {

	if (symbol == '&' || symbol == '#' || symbol == '+') {

		switch (symbol)
		{
		case '&':
		{
			DrawandTriangle();
			break;
		}

		case '#':
		{
			DrawpoundTriangle();
			break;
		}

		case '+':
		{
			DrawplusTriangle();
			break;
		}

		}
	}
	else {
		cout << "Please submit a valid symbol ( & , # , + ), Please try Again...\n";
		AskSymbol();
	}
}

void Triangle::DrawandTriangle() {

	for (int i = 0; i < userNum + 1; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < i; k++) {
			cout << "& ";
		}

		cout << endl;
	}

}

void Triangle::DrawpoundTriangle() {

	for (int i = 0; i < userNum + 1; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < i; k++) {
			cout << "# ";
		}

		cout << endl;
	}

}

void Triangle::DrawplusTriangle() {

	for (int i = 0; i < userNum + 1; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < i; k++) {
			cout << "+ ";
		}

		cout << endl;
	}

}

