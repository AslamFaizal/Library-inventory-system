/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-13
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 1   *****************************


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>

#include "Menu.h"

using namespace std;

namespace sdds {

    MenuItem::MenuItem(const char* description) {
        Food_Desc = new char[strlen(description) + 1];
        strcpy(Food_Desc, description);
    }

    MenuItem::~MenuItem() {       //destructor to reset the Food_Desc from the MenuItem
        delete[] Food_Desc;
    }

    MenuItem::operator bool()const {
        return (Food_Desc == nullptr);
    }

    MenuItem::operator const char* ()const {
        return Food_Desc;
    }

    ostream& MenuItem::display(ostream& os)const {
        if (Food_Desc != nullptr) {
            os << Food_Desc;
        }
        return os;
    }

    Menu::Menu(const char* Title) {
        Food_Title = new MenuItem(Title);
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            Food_Lists[i] = nullptr;
        }
        Food_Alloc = 0;
    }

    Menu::~Menu() {           //Reset the Menu with the help of destructor
        for (int i = 0; i < Food_Alloc; i++) {
            delete Food_Lists[i];
        }
        delete Food_Title;
    }

    ostream& Menu::displayTitle(ostream& os) const {
        Food_Title->display(os);
        return os;
    }

    ostream& Menu::displayAllMenu(ostream& os) const {
        if (Food_Alloc > 1){
            displayTitle(os) << ":" << endl;
            for (int i = 0; i < Food_Alloc; i++) 
            {
                os << " " << i + 1 << "- " << Food_Lists[i]->Food_Desc << endl;
            }
            os << " 0- Exit" << endl << "> ";
        } else {
            for (int i = 0; i < Food_Alloc; i++) {
                os << " " << i + 1 << "- " << Food_Lists[i]->Food_Desc << endl;
            }
            os << " 0- Exit" << endl << "> ";
        }
        return os;
    }

    unsigned int Menu::run() {
        displayAllMenu();
        int User_Input;
        int flag = 1;   
        //Here the statements needs to be true that's why using flag=1
        do {
            cin >> User_Input;
            if (cin.fail()) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
            } else if (User_Input < 0 || User_Input > Food_Alloc) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
            } else if (User_Input == 0) {
                flag = 0;
            } else if (User_Input > 0 || User_Input <= Food_Alloc) {
                flag = 0;
            }
            cin.ignore(1000, '\n');
        } while (flag);
        return User_Input;
    }

    unsigned int Menu::operator~() {
        int i = run();
        return i;
    }

    Menu& Menu::operator<<(const char* var) {
        if (Food_Alloc < MAX_MENU_ITEMS) {
            Food_Lists[Food_Alloc] = new MenuItem(var);
            Food_Alloc++;
        }
        return *this;
    }

    Menu::operator unsigned int()const {
        return Food_Alloc;
    }

    Menu::operator bool()const {
        return Food_Alloc > 0;
    }

    const char* Menu::operator[](int Index)const {
        return (const char*)*Food_Lists[Index];
    }

    ostream& operator<<(ostream& os, const Menu& var) {
        var.displayTitle(os);
        return os;
    }
}