#include "SaveManager.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"


map<int, string> SaveManager::shapeMap;


void SaveManager::SaveShape(int id, const string& type, int height, int width) {
	
	ofstream file("shapes.txt", ios::app);

	if (file.is_open()) {

		file << id << " " << type << " " << height << " " << width << endl;
		file.close();

		SaveToMem(id, type);
		cout << type << " saved with ID: " << id << endl;

	} else {

		cout << "Error Saving Shape! " << endl;

	}
}
