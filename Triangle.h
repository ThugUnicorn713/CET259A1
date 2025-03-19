#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "SaveManager.h"

using namespace std;

class Triangle
{
private:
	int userNum;
	string saveAnswer;
	char userSymbol;
	SaveManager* sm;

public:
	Triangle(SaveManager* manager);
	
	void TriAsk();
	void AskSymbol();
	void SaveAsk();
	
	void DrawTriangle(int height);
	void DrawandTriangle();
	void DrawpoundTriangle();
	void DrawplusTriangle();
	void SymbolSwitch(char symbol);
};


#endif 

