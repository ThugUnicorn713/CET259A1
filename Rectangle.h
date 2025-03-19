#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>
#include "SaveManager.h"
#include "Shape.h"

using namespace std;

class SaveManager;

class Rectangle : public Shape {
private: 
	int height;
	int width;
	int symHeight;
	int symWidth;
	char userSymbol;
	string saveAnswer;
	//SaveManager* sm;


public:
	Rectangle(SaveManager* manager);

	void RectAsk();
	void AskSymbol();
	void SaveAsk();
	void DrawRectangle(int height, int width);
	void DrawandRectangle();
	void DrawpoundRectangle();
	void DrawplusRectangle();
	void SymbolSwitch(char symbol);
};


#endif 
