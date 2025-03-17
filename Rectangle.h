#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>
#include "SaveManager.h"

using namespace std;


class Rectangle {
private: 
	int height;
	int width;
	int symHeight;
	int symWidth;
	char userSymbol;
	string saveAnswer;


public:

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
