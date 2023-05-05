
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-04
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 4  *****************************

#include <iostream>
#include<iomanip>
#include<cstring>

#include "Utils.h"

using namespace std;


namespace sdds {
    int getIntegerInput(int minRange, int maxRange) {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input;
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                validInt = false;
            }
            else
            {
                validInt = true;
            }

        }
        return input;
    }
}

