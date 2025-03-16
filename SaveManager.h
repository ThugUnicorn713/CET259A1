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
	static map<int, string> shapeMap;

public:
	static void SaveShape(int id, const string& type, int height, int width = 0);
	static void LoadShape(int id);
	static void SaveToMem(int id, const string& type);
};
#endif

