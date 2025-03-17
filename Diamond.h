#ifndef DIAMOND_H
#define DIAMOND_H

#include <iostream>
#include "SaveManager.h"

using namespace std;

class Diamond
{
private:
	int userNum;
	char userSymbol;
	string saveAnswer;
public:
	

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
