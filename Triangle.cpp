#include "Triangle.h"
#include "SaveManager.h"
#include <iostream>

using namespace std;

/*Triangle::Triangle(SaveManager* manager) {
	sm = manager;  // Use existing SaveManager instead of creating a new one
}*/

Triangle::Triangle(SaveManager* manager) : Shape(manager) {}

void Triangle::TriAsk() {

	do {
		cout << "Please input the number height of your Triangle (5 - 50) :";
		cin >> userNum;

		if (userNum > 50 || userNum < 5) {
			cout << " Sorry that input was invalid. Please enter values between 2 and 50." << endl;
		}

	} while (userNum > 50 || userNum < 5); 


	DrawTriangle(userNum);
	AskSymbol();

}

void Triangle::SaveAsk() {
	
	while (true) {

		cout << "Would you like to save this shape? (Y/N)" << endl;
		cin >> saveAnswer;

		if (saveAnswer == "Y" || saveAnswer == "y") {

			int id; 
			
			cout << "Please Enter ID for this Triangle: ";
			cin >> id;
			

			sm->SaveShape(id, "Triangle", userNum);
			sm->SaveToFile();
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

void Triangle::AskSymbol() {
	char difSymbol;

	cout << "Would you like a different symbol? (Y/N)";
	cin >> difSymbol;

	if (difSymbol == 'Y' || difSymbol == 'y') {

		cout << " Which symbol? ( & , # , + ) ";
		cin >> userSymbol;
		SymbolSwitch(userSymbol);

	}
	else {
		SaveAsk();
	}
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

	SaveAsk();
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

	SaveAsk();
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

	SaveAsk();
}

