#include "Diamond.h"
#include "SaveManager.h"
#include <iostream>
using namespace std;


/*Diamond::Diamond(SaveManager* manager) {
	sm = manager;  // Use existing SaveManager
}*/

Diamond::Diamond(SaveManager* manager) : Shape(manager) {}

void Diamond::DiaAsk() {

	do {
		cout << "Please input the number height of your Diamond (5 - 50) :";
		cin >> userNum;

		if (userNum > 50 || userNum < 5) {
			cout << " Sorry that input was invalid. Please enter values between 2 and 50." << endl;
		}

	} while (userNum > 50 || userNum < 5); 


	DrawDiamond(userNum);
	AskSymbol();

}

void Diamond::AskSymbol() {

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

void Diamond::SaveAsk() {

	while (true) {

		cout << "Would you like to save this shape? (Y/N)" << endl;
		cin >> saveAnswer;

		if (saveAnswer == "Y" || saveAnswer == "y") {

			int id;

			cout << "Please create ID for this Diamond: ";
			cin >> id;


			sm->SaveShape(id, "Diamond", userNum);
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

void Diamond::DrawDiamond(int height) {

	for (int i = 1; i <= height; i++) {

		for (int j = 0; j < height - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "*";
		}

		cout << endl;
	}


	for (int i = height - 1; i >= 1; i--) {

		for (int j = 0; j < height - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "*";
		}

		cout << endl;
	}
}

void Diamond::SymbolSwitch(char symbol) {

	if (symbol == '&' || symbol == '#' || symbol == '+') {

		switch (symbol)
		{
		case '&':
		{
			DrawandDiamond();
			break;
		}

		case '#':
		{
			DrawpoundDiamond();
			break;
		}

		case '+':
		{
			DrawplusDiamond();
			break;
		}

		}
	}
	else {
		cout << "Please submit a valid symbol ( & , # , + ), Please try Again...";
		AskSymbol();
	}
}


void Diamond::DrawandDiamond() {

	do {
		cout << "Please input the number height of your Diamond (5 - 50) :";
		cin >> userNum;

	} while (userNum >= 50 && userNum <= 5);

	for (int i = 1; i <= userNum; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "&";
		}

		cout << endl;
	}


	for (int i = userNum - 1; i >= 1; i--) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "&";
		}

		cout << endl;
	}

	SaveAsk();
}

void Diamond::DrawpoundDiamond() {

	for (int i = 1; i <= userNum; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "#";
		}

		cout << endl;
	}


	for (int i = userNum - 1; i >= 1; i--) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "#";
		}

		cout << endl;
	}
	SaveAsk();
}

void Diamond::DrawplusDiamond() {

	for (int i = 1; i <= userNum; i++) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "+";
		}

		cout << endl;
	}


	for (int i = userNum - 1; i >= 1; i--) {

		for (int j = 0; j < userNum - i; j++) {
			cout << " ";
		}

		for (int k = 0; k < (2 * i - 1); k++) {
			cout << "+";
		}

		cout << endl;
	}

	SaveAsk();
}
