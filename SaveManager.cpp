#include "SaveManager.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"


void SaveManager::SaveShape(int id, const string& type, int height, int width) {
	int* idPtr = new int(id);

	shapeMap[idPtr] = type;
	shapeHeights[idPtr] = height;

	if (type == "Rectangle") {
		shapeWidths[idPtr] = width;
	}

	ofstream file("shapes.txt", ios::app);

	if (file) {

		file << id << " " << type << " " << height << " " << width << endl;
		file.close();

		cout << type << " Shape saved with ID: " << *idPtr << endl;

	} else {

		cout << "Could not save Shape! " << endl;

	}

}

void SaveManager::LoadShape(int id) {
	
	for (auto& pair : shapeMap) {
		if (*(pair.first) == id) {
			
			string type = pair.second;
			
			int height = shapeHeights[pair.first];
			int width = shapeWidths[pair.first];

			if (type == "Triangle") {

				Triangle t;
				t.DrawTriangle(height);

			}
			else if (type == "Rectangle") {
				
				Rectangle r;
				r.DrawRectangle(height, width);

			}
			else if (type == "Diamond") {
				Diamond d;
				d.DrawDiamond(height);
			}

			return;
		}
	}
	cout << "Shape ID not found. " << endl;
}

void SaveManager::SaveToFile() {

	ofstream file("shapes.txt");

	if (file) {

		for (auto& pair : shapeMap) {
			file << *(pair.first) << " " << pair.second << " " << shapeHeights[pair.first] << " "
				<< (pair.second == "Rectangle" ? shapeWidths[pair.first] : 0) << endl;
		}

		file.close();
	}
}

void SaveManager::LoadFromFile() {

	ifstream file("shapes.txt");

	if (file) {
		
		int id, height, width;
		string type; 

		while (file >> id >> type >> height >> width) {

			SaveShape(id, type, height, width);
			break;
		}

		file.close();

	}

}

SaveManager::~SaveManager() {
	
	for (auto& pair : shapeMap) {

		delete pair.first;
	}

	shapeMap.clear();
	shapeHeights.clear();
	shapeWidths.clear();

}
