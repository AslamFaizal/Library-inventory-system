
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 2   *****************************

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {

    class LibApp {

        bool m_changed = false;
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        bool confirm(const char* message);
        void load();               // prints: "Loading Data"<NEWLINE>
        void save();               // prints: "Saving Data"<NEWLINE>
        void search();             // prints: "Searching for publication"<NEWLINE>
        void returnPub();          /*  Calls the search() method.
        prints "Returning publication" < NEWLINE >
            prints "Publication returned" < NEWLINE >
            sets m_changed to true;
        */
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:

        LibApp();
        void run();

    };
}
#endif 

