
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-04
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 4  *****************************

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>
#include<iomanip>

namespace sdds {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;  
        virtual bool conIO(std::ios& io) const = 0;       
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    
    std::ostream& operator<<(std::ostream& os, const Streamable& s);
    std::istream& operator>>(std::istream& is, Streamable& s);
}

#endif //SDDS_STREAMABLE_H
