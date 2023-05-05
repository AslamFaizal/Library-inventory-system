
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 2   *****************************

#include<iostream>
#include<iomanip>

#include "LibApp.h"

using namespace std;

namespace sdds {

    bool LibApp::confirm(const char* message)
    {
        Menu display(message);
        display << "Yes";

        int t_return = display.run();
        if (t_return) return true;

        return false;
    }

    void LibApp::load() { std::cout << "Loading Data\n"; }  // prints: "Loading Data"<NEWLINE>
    void LibApp::save() { std::cout << "Saving Data\n"; }   // prints: "Saving Data"<NEWLINE>
    void LibApp::search() { std::cout << "Searching for publication\n"; }   // prints: "Searching for publication"<NEWLINE>

    void LibApp::returnPub()  /*  Calls the search() method.
                           prints "Returning publication"<NEWLINE>
                           prints "Publication returned"<NEWLINE>
                           sets m_changed to true;
                       */
    {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n";
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library\n";

        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added\n";
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library\n";

        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;

            cout << "Publication removed\n";
        }

    }

    void LibApp::checkOutPub()
    {
        search();

        if (confirm("Check out publication?"))
        {
            m_changed = true;

            cout << "Publication checked out\n";
        }


    }

    LibApp::LibApp()
    {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }




    void LibApp::run()
    {
        while (1)
        {
            int option = m_mainMenu.run();

            if (option == 1)
            {
                newPublication();
            }
            else if (option == 2)
            {
                removePublication();
            }
            else if (option == 3)
            {
                checkOutPub();
            }
            else if (option == 4)
            {
                returnPub();
            }
            else if (option == 0)
            {
                if (m_changed)
                {

                    int opn = m_exitMenu.run();

                    if (opn == 1)
                    {
                        save();
                        break;
                    }
                    else if (opn == 2)
                    {
                        ;
                    }
                    else if (opn == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                            break;
                    }

                }
                else break;


            }

            cout << std::endl;
        }

        cout << std::endl;
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";
    }

}
