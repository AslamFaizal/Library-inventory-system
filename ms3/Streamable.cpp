/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 3  *****************************

#include<iostream>
#include<iomanip>
#include<cstring>

#include"Streamable.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& os, const Streamable& obj) {
        obj.write(os);
        return os;
    }

    istream& operator>>(istream& is, Streamable& obj) {
        obj.read(is);
        return is;
    }
}
