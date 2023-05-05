/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 5   *****************************


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>

#include"Utils.h"

unsigned int const  MAX_MENU_ITEMS = 20;

namespace sdds {
	class MenuItem {

	private:                   //MenuItem private members
		char* item;
		MenuItem();
		MenuItem(const char* Items);
		operator char* () const;
		operator bool() const;
		std::ostream& write(std::ostream& os = std::cout)const;
		~MenuItem();
		 
	public:                       //MenuItem public members
		friend class Menu;
	};

	class Menu {
	private:
		MenuItem* title;
		MenuItem* itemList[MAX_MENU_ITEMS];
		unsigned int no_of_items;

	public:
		Menu();
		Menu(const char* Items);
		std::ostream& display(std::ostream& os = std::cout)const;
		unsigned int run();
		unsigned int operator ~();
		Menu& operator<<(const char* Contents);
		std::ostream& displayT(std::ostream& os);
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator [](int i)const;

		~Menu();
	};

	std::ostream& operator<<(std::ostream& os, Menu& menu);
}
#endif 