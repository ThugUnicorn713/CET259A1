#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stack>

class Triangle;   //Forward declaration (just tells the compiler the class exists)
class Rectangle;
class Diamond;
class MenuSystem;

using namespace std;

struct ShapeState {
	int id;
	string shapeName;
	int height;
	int width;

	ShapeState(int shapeID, const string& name, int h, int w)
		: id(shapeID), shapeName(name), height(h), width(w) {}
};

class SaveManager
{
private:
	map<int*, string> shapeMap;
	map<int*, int> shapeHeights;
	map<int*, int> shapeWidths;
	MenuSystem* menuSystem;
	char saveAnswer;

	stack<ShapeState> undoStack;
	stack<ShapeState> redoStack;

public:
	SaveManager(MenuSystem* ms);

	 void SaveShape(int id, const string& type, int height, int width = 0);
	 void LoadShape(int id);
	 void SaveToFile();
	 void LoadFromFile();
	 void DeleteShape(int id);

	 void MoveShape(int id);
	 void ResizeShape(int id);
	 void ChangeShape(int id);
	 void RandomShape();

	 void Undo();
	 void Redo();

	~SaveManager();

};
#endif

