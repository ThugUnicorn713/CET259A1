#include "Triangle.h"
#include "SaveManager.h"
#include <iostream>

using namespace std;

//Triangle::Triangle(int h) {
	//userNum = h;  //might work or maybe try height
//}

void Triangle::TriAsk() {

	do {
		cout << "Please input the number height of your Triangle (5 - 50) :";
		cin >> userNum;

	} while (userNum >= 50 && userNum <= 5); // add validation 


	DrawTriangle(userNum);
	SaveAsk();

}

void Triangle::SaveAsk() {

	SaveManager sm;
	int loadNum;
	
	while (true) {

		cout << "Would you like to save this shape? (Y/N)" << endl;
		cin >> saveAnswer;

		if (saveAnswer == "Y" || saveAnswer == "y") {

			int id; 
			
			cout << "Please Enter ID for this Triangle: ";
			cin >> id;
			

			sm.SaveShape(id, "Triangle", userNum);
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

	cout << "what is the ID of your shape? : " << endl; //Load logic
	cin >> loadNum;

	sm.LoadShape(loadNum);
	sm.LoadFromFile();
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

