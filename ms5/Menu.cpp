/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 5   *****************************


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<cstring>


#include"Utils.h"	
#include "Menu.h"

using namespace std;

namespace sdds {

	Menu::Menu() {
		title = new MenuItem();
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			itemList[i] = nullptr;
		}
		no_of_items = 0;
	}

	Menu::Menu(const char* Items) {
		{
			title = new MenuItem(Items);
		}
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			itemList[i] = nullptr;
		}
		no_of_items = 0;
	}

	std::ostream& Menu::display(std::ostream& os) const
	{
		if ((const char*)(*title) != nullptr) {
			os << (const char*)(*title);
			os << std::endl;
		}
		for (unsigned int i = 0; i < no_of_items; i++) {
			os << " " << i + 1 << "- ";
			os << (const char*)(*itemList[i]);
			os << std::endl;
		}
		os << " 0- Exit" << std::endl << "> ";


		return os;
	}

	unsigned int Menu::run()
	{
		display();
		return getIntInRange(0, no_of_items);
	}

	unsigned int Menu::operator~()
	{
		return run();
	}
	Menu& Menu::operator<<(const char* Contents)
	{
		if (no_of_items < MAX_MENU_ITEMS) {
			itemList[no_of_items] = new MenuItem(Contents);
			no_of_items++;
		}

		return *this;
	}

	Menu::~Menu() {
		delete title;
		for (unsigned int i = 0; i < no_of_items; i++) {
			delete itemList[i];
			itemList[i] = nullptr;
		}

	}
	Menu::operator int()
	{
		return no_of_items;
	}

	std::ostream& Menu::displayT(std::ostream& os)
	{
		if ((const char*)(*title) != nullptr) {
			os << (const char*)(*title);
		}
		return os;
	}

	Menu::operator unsigned int()
	{
		return no_of_items;
	}
	Menu::operator bool()
	{
		return no_of_items >= 1;
	}

	const char* Menu::operator[](int i) const
	{
		return (const char*)(*itemList[i % no_of_items]);
	}


	std::ostream& operator<<(std::ostream& os, Menu& menu) {
		return menu.displayT(os);

	}

	MenuItem::MenuItem() {
		item = nullptr;
	}
	MenuItem::MenuItem(const char* Items) {

		item = new char[strlen(Items) + 1];
		strcpy(item, Items);
	}

	MenuItem::operator char* () const {
		return item;
	}
	MenuItem::operator bool() const {
		return item != nullptr;
	}
	std::ostream& MenuItem::write(std::ostream& os)const {
		if (item != nullptr) {
			os << item;
		}
		return os;
	}
	MenuItem::~MenuItem() {
		if (item != nullptr)
			delete[] item;
	}
}