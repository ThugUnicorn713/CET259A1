#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

class Triangle
{
private:
	int userNum;
	char userSymbol;

public:
	void TriAsk();
	void AskSymbol();
	void DrawTriangle(int height);
	void DrawandTriangle();
	void DrawpoundTriangle();
	void DrawplusTriangle();
	void SymbolSwitch(char symbol);
};


#endif 

