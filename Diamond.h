#ifndef DIAMOND_H
#define DIAMOND_H

#include <iostream>


class Diamond
{
private:
	int userNum;
	char userSymbol;
public:
	

	void DiaAsk();
	void AskSymbol();
	void DrawDiamond(int height);
	void DrawandDiamond();
	void DrawpoundDiamond();
	void DrawplusDiamond();
	void SymbolSwitch(char symbol);
};

#endif
