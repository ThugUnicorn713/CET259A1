#include "SaveManager.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"
#include "MenuSystem.h"
#include <fstream>
#include <string>
#include <stack>


SaveManager::SaveManager(MenuSystem* ms) : menuSystem(ms) {
	// knows what menusystem is 
}

void SaveManager::SaveShape(int id, const string& type, int height, int width) {

	int* idPtr = new int(id);

	cout << shapeMap[idPtr] << endl;

	// Save the current state for undo
	ShapeState currentState(id, shapeMap[idPtr], shapeHeights[idPtr], shapeWidths[idPtr]);
	undoStack.push(currentState);

	while (!redoStack.empty()) {
		redoStack.pop();
	}

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

	int* existID = nullptr;
	
	for (auto& pair : shapeMap) {
		if (*(pair.first) == id) {
			
			existID = pair.first;
			break;
		}
	}
	
	if (!existID) {

		cout << "Shape ID not found....Returning to Main Menu " << endl;
		menuSystem->CallMenu();
		return;
	}
	

	string type = shapeMap[existID];

	int height = shapeHeights[existID];
	int width = (type == "Rectangle") ? shapeWidths[existID] : 0;

	if (type == "Triangle") {

		Triangle t(this);
		t.DrawTriangle(height);

	}
	else if (type == "Rectangle") {

		Rectangle r(this);
		r.DrawRectangle(height, width);

	}
	else if (type == "Diamond") {
		Diamond d(this);
		d.DrawDiamond(height);
	}
}

void SaveManager::SaveToFile() {

	char undoAnswer;

	ofstream file("shapes.txt");

	if (file) {

		for (auto& pair : shapeMap) {
			file << *(pair.first) << " " << pair.second << " " << shapeHeights[pair.first] << " "
				<< (pair.second == "Rectangle" ? shapeWidths[pair.first] : 0) << endl;
		}

		file.close();
	}

	cout << "Would you like to undo this save? (Y/N)" << endl;
	cin >> undoAnswer;

	if (undoAnswer == 'Y' || undoAnswer == 'y') {

		cout << " Undoing last save....." << endl;
		Undo();
	}
	else {
		cout << "Keeping save" << endl;
		menuSystem->CallMenu();
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

	int* idToDelete = nullptr;

	for (auto& pair : shapeMap) {
		
		if (*(pair.first) == id) {
			
			idToDelete = pair.first;
			break;
		}
	}

	if (!idToDelete) {

		cout << " Shape ID was not found! loading Main Menu....." << endl;
		menuSystem->CallMenu();
		return;
	}

	cout << "Deleting Shape with ID: " << *idToDelete << endl;
	
	shapeMap.erase(idToDelete);
	shapeHeights.erase(idToDelete);
	shapeWidths.erase(idToDelete);

	delete idToDelete;

	cout << "Shape with ID : " << id << "  deleted successfully." << endl;

	cout << "Would you like to save this change? (Y/N)"; //val & method?
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
		cout << "Saving DONE!\n";
		
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "Going back to main menu...." << endl;
		
	}

	menuSystem->CallMenu();
}

void SaveManager::MoveShape(int id) {
	int spaces;

	cout << "Enter how many spaces you would like to move your Shape." << endl;
	cin >> spaces;

	cout << "Moving shape by " << spaces << " spaces...." << endl;

	for (int i = 0; i < spaces; i++) {

		cout << endl;
	}

	LoadShape(id);

	cout << "Isnt that cool? Going back to main menu now...." << endl;
	menuSystem->CallMenu();
	
}

void SaveManager::ResizeShape(int id) {

	int newHeight, newWidth;

	int* existID = nullptr;

	for (auto& pair : shapeMap) {

		if (*(pair.first) == id) {

			existID = pair.first;
			break;
		}
	}

	if (!existID) {
		cout << "Shape ID not found....Returning to Main Menu " << endl;
		menuSystem->CallMenu();
		return;
	}

	cout << "Please enter new Height: ";
	cin >> newHeight;

	if (shapeMap[existID] == "Rectangle") {
		cout << "Please enter new Width: ";
		cin >> newWidth;
	}
	else {
		newWidth = 0;
	}

	shapeHeights[existID] = newHeight;
	if (newWidth > 0) shapeWidths[existID] = newWidth;

	cout << "Shape Resized!...Redrawing now" << endl;
	LoadShape(id);

	cout << "Would you like to save this change? (Y/N)"; //save method
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
		cout << "Saving DONE!\n";
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "No Changes made! Going back to main menu...." << endl;
	}

	menuSystem->CallMenu();
}

void SaveManager::ChangeShape(int id) {
	
	int newShape;
	string newShapeName;
	int* existID = nullptr;


	cout << "Choose a new shape:\n";
	cout << "1) Rectangle\n";
	cout << "2) Triangle\n";
	cout << "3) Diamond\n";
	cin >> newShape;


	switch (newShape) {
		case 1: newShapeName = "Rectangle"; break;
		case 2: newShapeName = "Triangle"; break;
		case 3: newShapeName = "Diamond"; break;

		default:
			cout << "Not a valid shape! Returning to menu..." << endl;
			return;
	}

	for (auto& pair : shapeMap) {

		if (*(pair.first) == id) {

			existID = pair.first;
			break;
		}
	}

	if (!existID) {
		cout << "Shape ID not found....Returning to Main Menu " << endl;
		menuSystem->CallMenu();
		return;
	}

	shapeMap[existID] = newShapeName;
	int newHeight = shapeHeights[existID];
	int newWidth = shapeWidths[existID];

	if (newShapeName == "Rectangle") {
		cout << "Please enter the new width: ";
		cin >> newWidth;
	}
	else if (newShapeName == "Triangle" || newShapeName == "Diamond") {
		newWidth = 0; 
	}

	// Update the properties
	shapeHeights[existID] = newHeight;
	shapeWidths[existID] = newWidth;

	cout << " Shape is changed to " << newShapeName << " Redrawing now!..." << endl;
	LoadShape(id);

	cout << "Would you like to save this change? (Y/N)";  //save method
	cin >> saveAnswer;

	if (saveAnswer == 'Y' || saveAnswer == 'y') {

		SaveToFile();
		cout << "Saving DONE!\n";
	}
	else if (saveAnswer == 'N' || saveAnswer == 'n') {

		cout << "Going back to main menu...." << endl;
		
	}

	menuSystem->CallMenu();
}

void SaveManager::RandomShape() {

	int shapeType = rand() % 3;
	int height = rand() % 20 + 5;
	int width = (shapeType == 0) ? rand() % 20 + 3 : 0;

	string shapeName;

	if (shapeType == 0) {
		shapeName = "Rectangle";
	}
	else if (shapeType == 1) {
		shapeName = "Triangle";
	}
	else {
		shapeName = "Diamond";
	}

	cout << "Generated a random " << shapeName << " with height: " << height;
	if (shapeType == 0) cout << " and width: " << width;
	cout << endl;

	if (shapeType == 0) {

		Rectangle r(this);
		r.DrawRectangle(height, width);
	}
	else if (shapeType == 1) {

		Triangle t(this);
		t.DrawTriangle(height);
	}
	else {

		Diamond d(this);
		d.DrawDiamond(height);
	}

	char saveChoice;
	cout << "Would you like to save this shape? (Y/N): ";
	cin >> saveChoice;

	if (saveChoice == 'Y' || saveChoice == 'y') {

		int id = rand() % 20;
		SaveShape(id, shapeName, height, width);
		cout << shapeName << " with ID " << id << " has been saved!" << endl;
	}
	else {
		cout << "Shape not saved. Returning to main menu..." << endl;
	}

	menuSystem->CallMenu();
}

void SaveManager::Undo() {

	char redoAnswer;

	if (!undoStack.empty()) {

		ShapeState lastState = undoStack.top();
		undoStack.pop();

		// Correct the lines by dereferencing lastState.id
		redoStack.push(lastState);

		cout << lastState.shapeName << endl; //this doesnt happen

		// Revert to the previous state (use dereferencing to access the pointer's value)
		shapeMap[&(lastState.id)] = lastState.shapeName;
		shapeHeights[&(lastState.id)] = lastState.height;
		shapeWidths[&(lastState.id)] = lastState.width;

		cout << "Shape with ID " << lastState.id << " restored to its former Glory!" << endl;
	}
	else {
		cout << "No previous changes to undo." << endl;
		menuSystem->CallMenu();

	}

	cout << " Redo last save you just undid? (Y/N) " << endl;
	cin >> redoAnswer;

	if (redoAnswer == 'Y' || redoAnswer == 'y') {

		cout << " Redoing last save....." << endl;
		Redo();
	}
	else {
		cout << "Keeping Undo Action." << endl;
		menuSystem->CallMenu();
	}

}

void SaveManager::Redo() {


	if (!redoStack.empty()) {
		
		ShapeState lastState = redoStack.top();
		redoStack.pop();

		undoStack.push(ShapeState(lastState.id, shapeMap[&lastState.id], shapeHeights[&lastState.id], shapeWidths[&lastState.id]));

		shapeMap[&(lastState.id)] = lastState.shapeName;
		shapeHeights[&(lastState.id)] = lastState.height;
		shapeWidths[&(lastState.id)] = lastState.width;

		cout << " Shape with ID " << lastState.id << " restored! HUZZAH!!!" << endl;
		menuSystem->CallMenu();

	}
	else {
		cout << "No actions to redo" << endl;
		menuSystem->CallMenu();
	}

	
}

SaveManager::~SaveManager() {

	// Clear undo and redo stacks
	while (!undoStack.empty()) {
		undoStack.pop();
	}
	while (!redoStack.empty()) {
		redoStack.pop();
	}
	
	for (auto& pair : shapeMap) {

		delete pair.first;
	}

	shapeMap.clear();
	shapeHeights.clear();
	shapeWidths.clear();

}
