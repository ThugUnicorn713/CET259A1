#include "Diamond.h"
#include <iostream>
//#include <conio.h>
using namespace std;


void Diamond::DiaAsk() {

	do {
		cout << "Please input the number height of your Diamond (5 - 50) :";
		cin >> userNum;

	} while (userNum >= 50 && userNum <= 5); // add validation 


	DrawDiamond(userNum);


}

void Diamond::AskSymbol() {

	cout << " Would you like to draw a Diamond in one of these symbols? ( & , # , + ) ";
	cin >> userSymbol;
	SymbolSwitch(userSymbol);
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

	AskSymbol();
	
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
}
