
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-04
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 4  *****************************

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {

    class Book : public Publication {
    private:
        char* authorName;
    public:
        Book();
        ~Book();

        
        Book(const Book& book);
        Book& operator=(const Book& book);        
        void setBookEmpty();        
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        virtual void set(int member_id);
        operator bool() const;
    };
}

#endif // SDDS_BOOK_H
