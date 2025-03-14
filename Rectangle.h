#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>


class Rectangle {
private: 
	int userNum;
	char userSymbol;

public:

	void RectAsk();
	void AskSymbol();
	void DrawRectangle(int height, int width);
	void DrawandRectangle();
	void DrawpoundRectangle();
	void DrawplusRectangle();
	void SymbolSwitch(char symbol);
};


#endif 
