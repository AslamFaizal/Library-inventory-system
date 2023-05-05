
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 2   *****************************


#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
using namespace std;

namespace sdds {

    int const MAX_MENU_ITEMS = 20;  //Using limit according to the project decription
    class Menu;

    class MenuItem {

        char* m_menuItem{};
        MenuItem();                            //Adding a constructor
        MenuItem(const char* Items);

        ~MenuItem();                           //Adding a destructor 
        operator bool() const;
        void display();
        friend class Menu;                     //Given
    };

    class Menu {                               //Declaring a class named Menu
        char* m_menuTitle{};
        MenuItem* m_items[MAX_MENU_ITEMS];
        int m_noofmenu = 0;

    public:                                    //Declaring them as public functions of the class
        Menu();
        Menu(const char* Title);
        ~Menu();

        int run();
        char* operator[](int i) const;
        operator bool() const;
        int operator~();

        void display();

        std::ostream& write(std::ostream& os = std::cout)const;
        Menu& operator<<(const char* Contents);
        operator unsigned int() const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& m);
}
#endif
