
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 3  *****************************



#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include<iostream>

using namespace std;

namespace sdds {
    class Streamable {        //Using abstract class 
    public:    //using pure virtual function as per the instructions
        virtual std::ostream& write(std::ostream& os)const = 0; 
        virtual std::ostream& read(std::istream& is) = 0; 
        virtual bool conIO(std::ios& io)const = 0; 
        virtual operator bool()const = 0; 
        virtual ~Streamable() {};

    };

    std::ostream& operator<<(std::ostream& os, const Streamable& obj);
    std::istream& operator>>(std::istream& is, Streamable& obj);
}

#endif
