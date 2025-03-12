#include "Triangle.h"
#include <iostream>

using namespace std;


void TriAsk();
void DrawTriangle(int height);

class Triangle
{
	void TriAsk();
};

void TriAsk() {

	int userHeight;

	do {
		cout << "Please input the number height of your Triangle (5 - 50) :";
		cin >> userHeight;

	} while (userHeight >= 50 && userHeight <= 5); // add validation 


	DrawTriangle(userHeight);


}

void DrawTriangle(int height) {

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
