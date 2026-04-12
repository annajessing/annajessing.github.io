# include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


#include "PurchasedProduce.h"

// Anna Jessing
// February 21, 2024

// This file contains all function definitions for the PurchasedProduce class

// used to push back an item to m_uniqueItemList
void PurchasedProduce::setValueInUniqueItemList(string t_itemName) {
	m_uniqueItemList.push_back(t_itemName);
}

// used to see if value already exists in m_uniqueItemList
bool PurchasedProduce::uniqueValueTest(std::string t_itemName) {
	bool uniqueValue = true;
	vector<string> currValues = getFullItemList();

	for (int i = 0; i < currValues.size(); ++i) {

		// if value already in vector, then not a unique item
		if (currValues.at(i) == t_itemName) {
			uniqueValue = false;
		}
	}
	return uniqueValue;
}

// functions used to return values of global variables
vector<string> PurchasedProduce::getFullItemList() const {
	return m_uniqueItemList;
}