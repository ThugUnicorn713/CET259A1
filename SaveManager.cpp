#include "SaveManager.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"
#include "MenuSystem.h"
#include <fstream>
#include <string>


void SaveManager::SaveShape(int id, const string& type, int height, int width) {
	cout << "SaveShape() is using shapeMap at memory address: " << &shapeMap << endl;

	MenuSystem ms;

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

		cout << type << " Shape saved with ID: " << *idPtr << " Going back to Main Menu...." << endl;
		ms.CallMenu();

	} else {

		cout << "Could not save Shape! " << endl;

	}

}

void SaveManager::LoadShape(int id) {

	MenuSystem ms;

	int* existID = nullptr;
	
	for (auto& pair : shapeMap) {
		if (*(pair.first) == id) {
			
			existID = pair.first;
			break;
		}
	}
	
	if (!existID) {

		cout << "Shape ID not found....Returning to Main Menu " << endl;
		ms.CallMenu();
		return;
	}
	

	string type = shapeMap[existID];

	int height = shapeHeights[existID];
	int width = (type == "Rectangle") ? shapeWidths[existID] : 0;

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
	cout << "LoadFromFile() is using shapeMap at memory address: " << &shapeMap << endl;

	ifstream file("shapes.txt");
	
	if (!file) {
		cout << "No previous shapes found.\n";
		return;
	}

	int id, height, width;
	string type;

	while (file >> id >> type >> height >> width) {
		int* shapeID = new int(id);
		
		shapeMap[shapeID] = type;
		shapeHeights[shapeID] = height;
		
		if (type == "Rectangle") {
			
			shapeWidths[shapeID] = width;
		}
	}

	file.close();

	cout << "Shapes Loaded from File:" << endl;
	for (auto& pair : shapeMap) {
		cout << "ID: " << *(pair.first) << ", Type: " << pair.second << endl;
	}
}

void SaveManager::DeleteShape(int id) {

	cout << "DeleteShape() is using shapeMap at memory address: " << &shapeMap << endl;

	
	MenuSystem ms;

	int* idToDelete = nullptr;

	cout << "Available Shapes Before Deletion: " << endl;
	for (auto& pair : shapeMap) {
		cout << "ID: " << *(pair.first) << ", Type: " << pair.second << endl;
	}


	for (auto& pair : shapeMap) {
		
		if (*(pair.first) == id) {
			
			idToDelete = pair.first;
			break;
		}
	}

	if (!idToDelete) {

		cout << " Shape ID was not found! loading Main Menu....." << endl;
		ms.CallMenu();
		return;
	}

	cout << "Deleting Shape with ID: " << *idToDelete << endl;
	
	shapeMap.erase(idToDelete);
	shapeHeights.erase(idToDelete);
	shapeWidths.erase(idToDelete);

	delete idToDelete;

	cout << "Shape with ID : " << id << "  deleted successfully." << endl;

	cout << "Would you like to save this change? (Y/N)"; // make a method with val
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "Going back to main menu...." << endl;
		ms.CallMenu();
	}
}

void SaveManager::MoveShape(int id) {

	MenuSystem ms;
	int spaces;

	cout << "Enter how many spaces you would like to move your Shape." << endl;
	cin >> spaces;

	cout << "Moving shape by " << spaces << " spaces...." << endl;

	for (int i = 0; i < spaces; i++) {

		cout << endl;
	}

	LoadShape(id);

	cout << "Would you like to save this change? (Y/N)"; // make a method with val
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {
		
		cout << "Going back to main menu...." << endl;
		ms.CallMenu();
	}
}

void SaveManager::ResizeShape(int id) {

	MenuSystem ms;
	int newHeight, newWidth;

	cout << "Please enter new Height: ";
	cin >> newHeight;

	if (shapeMap[&id] == "Rectangle") {
		cout << "Please enter new Width: ";
		cin >> newWidth;
	}
	else {
		newWidth = 0;
	}

	shapeHeights[&id] = newHeight;
	if (newWidth > 0) shapeWidths[&id] = newWidth;

	cout << "Shape Resized!...Redrawing now" << endl;
	LoadShape(id);

	cout << "Would you like to save this change? (Y/N)"; // make a method with val
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "Going back to main menu...." << endl;
		ms.CallMenu();
	}
}

void SaveManager::ChangeShape(int id) {
	
	MenuSystem ms;
	int newShape;
	string newShapeName;


	cout << "Choose a new shape:\n";
	cout << "1) Rectangle\n";
	cout << "2) Triangle\n";
	cout << "3) Diamond\n";
	cin >> newShape;


	switch (newShape) {
		case 1: newShapeName = "Rectangle"; break;
		case 2: newShapeName = "Triangle"; break;
		case 3: newShapeName + "Diamond"; break;

		default:
			cout << "Not a valid shape! Returning to menu..." << endl;
			return;
	}

	shapeMap[&id] = newShapeName;
	cout << " Shape is changed to " << newShapeName << " Redrawing now!..." << endl;
	LoadShape(id);

	cout << "Would you like to save this change? (Y/N)"; // make a method with val
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "Going back to main menu...." << endl;
		ms.CallMenu();
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
