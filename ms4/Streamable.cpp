

/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-04
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 4  *****************************
#include<algorithm>

#include "Streamable.h"

namespace sdds {
     Streamable::~Streamable() {};

    std::ostream& operator<<(std::ostream& os, const Streamable& s) {
        if (s) {
            s.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s) {
        return (s.read(is));
    }
}
