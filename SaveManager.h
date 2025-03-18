#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"

using namespace std;

class SaveManager
{
private:
	map<int*, string> shapeMap;
	map<int*, int> shapeHeights;
	map<int*, int> shapeWidths;
	char saveAnswer;

public:
	 void SaveShape(int id, const string& type, int height, int width = 0);
	 void LoadShape(int id);
	 void SaveToFile();
	 void LoadFromFile();
	 void DeleteShape(int id);

	 void MoveShape(int id);
	 void ResizeShape(int id);
	 void ChangeShape(int id);


	~SaveManager();

};
#endif

