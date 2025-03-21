#ifndef DIAMOND_H
#define DIAMOND_H

#include <iostream>
#include "SaveManager.h"
#include "Shape.h"

using namespace std;

class Diamond : public Shape
{
private:
	int userNum;
	char userSymbol;
	string saveAnswer;
	//SaveManager* sm;
public:
	Diamond(SaveManager* manager);

	void DiaAsk();
	void AskSymbol();
	void SaveAsk();
	void DrawDiamond(int height);
	void DrawandDiamond();
	void DrawpoundDiamond();
	void DrawplusDiamond();
	void SymbolSwitch(char symbol);
};

#endif
