#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// Anna Jessing
// February 21, 2024

#include "PurchasedProduce.h"

// used to print multiples of a character
// pieces of code utilized from sense instant feedback tool- https://its.sense.education/instant_feedback?t=res&token=3851F849-928A-4830-B1ED-3CEEB64DBD9C&user_id=3fe81883-35c7-4540-9944-b174fd5722a6_602502
string nCharString(size_t n, char c) {

	// return string
	string cString;

	// append the character to the end of string until string matches length of n
	for (int i = 0; i < n; ++i) {
		cString += c;
	}

	return cString;
}

// validate user input for Menu Option 1
string validateUserInput(const vector<string>completeItemList) {
	// user enters item to look up - using cin to remove whitespace
	string itemName;
	bool itemSold = false;

	cout << "Enter an item: ";
	cin >> itemName;

	//check to see if item is in vector
	for (int i = 0; i < completeItemList.size(); ++i) {		
		if (completeItemList.at(i) == itemName) {
			itemSold = true;
		}
	}

	// gather user input until a valid menu option is entered
	while (itemSold == false) {

		// give the user some direction as to what to do next
		cout << "That item was not sold or was entered incorrectly. Please try again." << endl;
		cout << "Enter an item: ";
		cin >> itemName;

		// check to see if item is in vector
		for (int i = 0; i < completeItemList.size(); ++i) {			
			if (completeItemList.at(i) == itemName) {
				itemSold = true;
			}
		}
	}

	return itemName;
}

// print frequency of a specific item
void frequencyOfOneItem(const vector<string>completeItemList, const map<string, int>frequencyItemSold) {
	
	// get input from user
	string itemName;
	itemName = validateUserInput(completeItemList);

	// print frequency of that item
	cout << itemName << " sold on the given date: " << frequencyItemSold.at(itemName) << endl;
}

// print all items and their frequency (numerical form)
void frequencyOfAllItemsNumerical(const vector<string>completeItemList, const map<string, int>frequencyItemSold) {
	for (int i = 0; i < completeItemList.size(); ++i) {
		// print "itemName itemFrequency" of all items
		cout << completeItemList.at(i) << " " << frequencyItemSold.at(completeItemList.at(i)) << endl;
	}

}

// print all items and their frequency (histogram form)
void frequencyOfAllItemsHistogram(const vector<string>completeItemList, const map<string, int>frequencyItemSold) {
	int currFrequency;

	for (int i = 0; i < completeItemList.size(); ++i) {
		
		// determine frequency of current item
		currFrequency= frequencyItemSold.at(completeItemList.at(i));

		// print the item name and one '*' for each time the item appears in the list (equal to frequency)
		cout << setw(11) << completeItemList.at(i) << " " << nCharString(currFrequency, '*') << endl;
	}

}

// print user menu
void printMenu() {

	int width = 60;

	// since the strings below are short in length and CONSTANT throughout the program, I printed them as is below
	cout << nCharString(width, '*') << endl;
	cout << "* 1 - Look Up Frequency of A Specific Item                 *" << endl;
	cout << "* 2 - Print All Items and Their Frequency (Numerical)      *" << endl;
	cout << "* 3 - Print All Items and Their Frequency (Histogram)      *" << endl;
	cout << "* 4 - Exit Program                                         *" << endl;
	cout << nCharString(width, '*') << endl;

}

// gather user input and validate it
unsigned int validateUserSelection() {

	// gather user input
	int menuSelection;
	cin >> menuSelection;

	// gather user input until a valid menu option is entered
	while ((menuSelection < 1) || (menuSelection > 4)) {

		// give the user some direction as to what to do next
		cout << "That is not an option. Please select a menu option." << endl;
		cin >> menuSelection;
	}

	return menuSelection;
}

// print menu, validate, and return user choice
int userMenuSelect(const vector<string>completeItemList, const map<string, int>frequencyItemSold) {

	// variable used to gather user choice
	// initialize as -1 to enter the loop
	int userChoice = -1;

	// loop through so the program runs until the user chooses to exit the program
	while (userChoice != 4) {

		// print user menu
		printMenu();

		// get input from user
		userChoice = validateUserSelection();

		// call proper function to execute the user's desired action
		if (userChoice == 1) {
			// return frequency for 1 item
			frequencyOfOneItem(completeItemList, frequencyItemSold);
		}
		else if (userChoice == 2) {
			// print all items and their frequency (as a number)
			frequencyOfAllItemsNumerical(completeItemList, frequencyItemSold);
		}
		else if (userChoice == 3) {
			// print all items and their frequency (as a histogram)
			frequencyOfAllItemsHistogram(completeItemList, frequencyItemSold);
		}
		else if (userChoice == 4) {
			// exit program
		}
	}

	return userChoice;	
}

// read file, store unique items in vector, store each item and its frequency in a map
void readToCollectPurchaseInfo(vector<string>& completeItemList, map<string, int>&frequencyItemSold) {
	
	// initialize class instance
	PurchasedProduce allPurchases;
	
	// variable to capture input file stream
	ifstream inFS;

	string itemName;	// read item name in file
	bool uniqueValue;	// validation tool to add itemName to vector

	// open file
	// note: I renamed file from CS210_Project_Three_Input_File.txt to CornerGrocer.txt
	inFS.open("CornerGrocer.txt");

	// check to see if file is open
	if (!inFS.is_open()) {
		cout << "CornerGrocer.txt is not open." << endl;
	}

	// if file is open then collect input
	else {

		// loop through file and store unqiue item names in a vector
		// store the number of times the item appears in the frequencyItemSold map

		// grab first item name
		inFS >> itemName;

		// check to see if error occured with input		
		while (!inFS.fail()) {

			// if no error, check to see if in vector
			uniqueValue = allPurchases.uniqueValueTest(itemName);

			// if not in vector, add to vector and create new map entry
			if (uniqueValue == true) {
				// push itemName to vector
				allPurchases.setValueInUniqueItemList(itemName);
				frequencyItemSold.emplace(itemName, 1);
			}

			// if in vector, update map entry: erase map entry for this item then re-create it with the new frequency value
			else {
				int currCount = frequencyItemSold.at(itemName);

				frequencyItemSold.erase(itemName);
				frequencyItemSold.emplace(itemName, currCount + 1);
			}

			// grab the next value
			inFS >> itemName;

			// loop back to validate input 
			// loop until end of file is reached
		}

		// done with file, so close it
		inFS.close();

		// return vector with a complete list of items sold
		completeItemList = allPurchases.getFullItemList();
	}
}

void writeBackupFile(vector<string>& completeItemList, map<string, int>& frequencyItemSold) {
	// create variable for output file stream
	ofstream outFS;

	// open file
	outFS.open("frequency.dat");

	// check to see if file is open
	if (!outFS.is_open()) {
		cout << "frequency.dat is not open." << endl;
	}

	// if open, write to backup file
	else {

		// completeItemList holds list of unique items in the file
		for (int i = 0; i < completeItemList.size(); ++i) {

			// write "itemName itemFrequency" to output file
			outFS << completeItemList.at(i) << " " << frequencyItemSold.at(completeItemList.at(i)) << endl;
		}

		// done with file, so close it
		outFS.close();

	}
}


int main() {

	// create map to store item and its frequency
	map<string, int> frequencyItemSold;

	// will hold a complete list of items sold
	vector<string> completeItemList; 

	// read and collect data from file
	readToCollectPurchaseInfo(completeItemList, frequencyItemSold);

	// create a backup file with the information
	writeBackupFile(completeItemList, frequencyItemSold);

	// call menu 
	userMenuSelect(completeItemList, frequencyItemSold);

	return 0;
}