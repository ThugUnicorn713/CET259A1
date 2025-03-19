#include "MenuSystem.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"
#include "SaveManager.h"
#include <iostream>

using namespace std;


MenuSystem::MenuSystem() {
	 sm = new SaveManager(this); 
}

void MenuSystem::CallMenu() {

	cout << "  " << endl;
	cout << "Welcome to your Shape Drawing Program!" << endl;
	cout << "   " << endl;
	cout << "Please Choose an Option from the Menu below." << endl;
	cout << "   " << endl;

	cout << "~ Shape Menu ~" << endl;
	cout << "1) Create Shape" << endl;
	cout << "2) Modify an Already Existing Shape" << endl;
	cout << "3) Delete a Saved Shape" << endl;
	cout << "4) Generate a Random Shape" << endl;
	cout << "5) Exit Program" << endl;
	cin >> userInput;

	MenuSwitch(userInput);
}

void MenuSystem::MenuSwitch(int userInput) {

	if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4 || userInput == 5) {

		switch (userInput) {

		case 1:
			cout << "What Shape would you like to create? " << endl;
			cout << "1) Rectangle" << endl;
			cout << "2) Triangle" << endl;
			cout << "3) Diamond" << endl;
			cin >> createInput;

			while (true) {

				if (createInput == 1) {

					Rectangle rect(sm);
					rect.RectAsk();
					break;

				}
				else if (createInput == 2) {

					Triangle tri(sm);
					tri.TriAsk();
					break;

				}
				else if (createInput == 3) {

					Diamond dia(sm);
					dia.DiaAsk();
					break;

				}
				else {
					cout << "Invalid entry, returning to Main Menu...." << endl; ;
					CallMenu();
				}
			}
			break;

		case 2:

			int loadNum;
			int modifyNum;

			cout << "what is the ID of your shape? : " << endl;
			cin >> loadNum;

			sm->LoadShape(loadNum);


			cout << "What would you like to modify Shape?\n";
			cout << "1) Move Shape\n";
			cout << "2) Resize Shape\n";
			cout << "3) Change Shape Type\n";
			cin >> modifyNum;

			switch (modifyNum) {
			case 1:
				sm->MoveShape(loadNum);
				break;
			case 2:
				sm->ResizeShape(loadNum);
				break;
			case 3:
				sm->ChangeShape(loadNum);
				break;
			default:
				cout << "Invalid choice. Returning to menu...\n";
				CallMenu();
			}
				break;

		case 3:

			int deleteID;

			cout << "What is the ID of the shape you want to delete?" << endl;
			cin >> deleteID;

			sm->DeleteShape(deleteID);
			break;

		case 4:

			sm->RandomShape();

		case 5: 

			cout << "Goodbye Friend!" << endl;
			exit(0);
			break;

		}

	}else {
		cout << "Please enter a Valid option..." << endl;
		CallMenu();

	}

	
	
}