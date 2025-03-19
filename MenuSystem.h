#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include <iostream>
#include "SaveManager.h"

using namespace std;

class SaveManager;

class MenuSystem
{
private:
	int userInput;
	int createInput;
	SaveManager* sm;

public:
	MenuSystem();
	~MenuSystem() { delete sm; } 

	void CallMenu();
	void MenuSwitch(int userInput);
};

#endif
