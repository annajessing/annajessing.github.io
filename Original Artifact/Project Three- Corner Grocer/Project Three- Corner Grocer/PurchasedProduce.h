#ifndef PROJECT THREE - CORNER GROCER APP_PROJECT THREE - CORNER GROCER APP_PURCHASEDPRODUCE_H
#define PROJECT THREE - CORNER GROCER APP_PROJECT THREE - CORNER GROCER APP_PURCHASEDPRODUCE_H

// Anna Jessing
// February 21, 2024

#include <string>
#include <map>
#include <vector>

class PurchasedProduce {
public:
	// since the only private member is the vector, and at this point those values are unknown, no contructor is defined

	// used to push back an item to m_uniqueItemList
	void setValueInUniqueItemList(std::string t_itemName);

	// used to see if value already exists in m_uniqueItemList
	bool uniqueValueTest(std::string t_itemName);

	// used to return values of global variables
	std::vector<std::string> getFullItemList() const;
	
private:
	// item names are stored in vector and frequencies are stored in map initialized in main.cpp
	// to store item names
	std::vector<std::string> m_uniqueItemList;
};

#endif // PROJECT THREE - CORNER GROCER APP_PROJECT THREE - CORNER GROCER APP_PURCHASEDPRODUCE_H
