/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-13
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 1   *****************************

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
    const int MAX_MENU_ITEMS = 20;  //Using limit according to the project decription
    class Menu;

    class MenuItem {

        char* Food_Desc;

        MenuItem(const char* desc = nullptr);  //Adding a constructor
        ~MenuItem();                           //Adding a destructor 
        MenuItem(const MenuItem& copy) = delete;
        MenuItem& operator=(const MenuItem& copy) = delete;
        operator bool()const;
        operator const char* ()const;
        std::ostream& display(std::ostream& os)const;

        friend class Menu;   //Given
    };

    class Menu {        //Declaring a class named Menu

        MenuItem* Food_Title;
        MenuItem* Food_Lists[MAX_MENU_ITEMS];
        int Food_Alloc;

    public:             //Declaring them as public functions of the class
        Menu(const Menu& copy) = delete;
        Menu& operator=(const Menu& copy) = delete;
        Menu(const char* title = "");
        virtual ~Menu();       //Adding Destructor
        std::ostream& displayTitle(std::ostream& os = std::cout)const;
        std::ostream& displayAllMenu(std::ostream& os = std::cout)const;
        unsigned int run();
        unsigned int operator~();
        Menu& operator<<(const char* var);
        operator unsigned int()const;
        operator bool()const;
        const char* operator[](int Index)const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& var);
}

#endif