
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 3  *****************************


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>

//Adding every header file into this file 
#include"Publication.h"
#include"Streamable.h"
#include"Lib.h"
#include"Date.h"


using namespace std;

namespace sdds {

    void Publication::extractChar(std::istream& istr, char Ch) const {
        if (istr.peek() == Ch) {
            istr.get();
        }
        else {
            istr.setstate(ios::failbit);
        }
    }

    void Publication::set(int member_id) {
        m_membership = member_id > 9999 && member_id <= 99999 ? member_id : 0;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date.setToToday();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {

        return m_date;
    }

    bool Publication::operator == (const char* title) const {
        if (strstr(m_title, title) != NULL) {
            return true;
        }
        return false;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(ios& ios) const {
        return &ios == &cin || &ios == &cout;
    }

    ostream& Publication::write(ostream& os) const {
        if (conIO(os)) {
            if (bool(*this)) {
                os << "| " <<
                    setw(SDDS_SHELF_ID_LEN) << left << setfill(' ') <<
                    m_shelfId <<
                    " | " <<
                    setw(SDDS_TITLE_WIDTH) << left << setfill('.') <<
                    m_title <<
                    " | ";
                m_membership == 0 ? os << " N/A " : os << m_membership;

                if (m_membership == 0)
                {
                    os << " | " << m_date << " |";
                }
                else
                {
                    os << " | " << m_date << " |";
                }
            }
        }
        else {
            if (bool(*this)) {
                os << type() << "\t" <<
                    m_libRef << "\t" <<
                    m_shelfId << "\t" <<
                    m_title << "\t" <<
                    m_membership << "\t" <<
                    m_date;
            }
        }
        return os;
    }

    istream& Publication::read(istream& istr) {
        if (m_title != nullptr)
            delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = ' ';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
        char* title = nullptr;
        title = new char[SDDS_TITLE_WIDTH + 1];
        char ShelfID[SDDS_SHELF_ID_LEN + 1]{};
        int Membership = 0;
        int Libref = -1;
        Date date;
        if (conIO(istr)) {
            cout << "Shelf No: ";
            istr.getline(ShelfID, SDDS_SHELF_ID_LEN + 1, '\n');
            if (strlen(ShelfID) != SDDS_SHELF_ID_LEN) {
                istr.setstate(ios::failbit);
            }
            cout << "Title: ";
            istr.getline(title, SDDS_TITLE_WIDTH + 1, '\n');
            cout << "Date: ";
            istr >> date;
            if (date.bad()) {
                istr.setstate(ios::failbit);
            }
        }
        else {
            istr >> Libref;
            extractChar(istr, '\t');
            istr >> ShelfID;
            extractChar(istr, '\t');
            if (ShelfID[0] == ' ') {
                istr.setstate(ios::failbit);
            }
            istr.getline(title, SDDS_TITLE_WIDTH + 1, '\t');
            if (title == nullptr || title[0] == ' ') {
                istr.setstate(ios::failbit);
            }
            if (istr.good()) {
                istr >> Membership;
                istr >> date;
            }
        }
        if (istr.rdstate() == 0) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, ShelfID);
            m_membership = Membership;
            m_date = date;
            m_libRef = Libref;
        }
        delete[] title;
        return istr;
    }

    Publication::Publication() {
        m_title = nullptr;
        m_shelfId[0] = ' ';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
    }

    Publication::operator bool() const {
        return m_title != nullptr || m_shelfId[0] != ' ';
    }

    ostream& operator << (ostream& os,
        const Publication& obj) {
        obj.write(os);
        return os;
    }

    istream& operator >> (istream& is, Publication& obj) {
        obj.read(is);
        return is;
    }

    Publication::Publication(const Publication& pub) {    //Using the constructor as publication
        if (pub.operator bool())
        {
            this->set(pub.m_title, pub.m_shelfId, pub.m_membership, pub.m_libRef, pub.m_date);
        }
    }

    Publication& Publication::operator = (const Publication& pub) {
        if (this != &pub) {
            this->set(pub.m_title, pub.m_shelfId, pub.m_membership,
                pub.m_libRef, pub.m_date);
        }
        return (*this);
    }

    Publication::~Publication() {    //Using the destructor
        delete[] m_title;
    }

    void Publication::set(const char* title,
        const char* ShelfID, int Membership,
        int Libref, Date date) {
        if (m_title != nullptr)
            delete[] m_title;
        m_title = nullptr;
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, ShelfID);
            m_membership = Membership;
            m_libRef = Libref;
            m_date = date;
        }
        else {
            m_shelfId[0] = ' ';
            m_membership = 0;
            m_libRef = -1;
            m_date.setToToday();
        }
    }
}
