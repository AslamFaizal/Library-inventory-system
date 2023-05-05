
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

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>

#include "Date.h"

using namespace std;

namespace sdds {

    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;

    bool Date::validate() {
        errCode(No_Errors_Caught);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(Wrong_Year);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(Wrong_Month);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(Wrong_Day);
        }
        return !bad();
    }

    int Date::mdays() const {
        int days[] = {
          31,
          28,
          31,
          30,
          31,
          30,
          31,
          31,
          30,
          31,
          30,
          31,
          -1
        };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    int Date::systemYear() const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(No_Errors_Caught);
    }

    int Date::daysSince0001_1_1() const { 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 +
            m_day - 306;
    }

    Date::Date() : m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    const char* Date::dateStatus() const {
        return Errors_in_Date[errCode()];
    }

    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    int Date::errCode() const {
        return m_ErrorCode;
    }

    bool Date::bad() const {
        return m_ErrorCode != 0;
    }

    ostream& operator << (ostream& os,
        const Date& RO) {
        return RO.write(os);
    }

    istream& operator >> (istream& is, Date& RO) {
        return RO.read(is);
    }


    //Asking for the input for year, month, date etc.
    std::istream& Date::read(std::istream& is) {     
        errCode(No_Errors_Caught);
        is >> m_year;
        is.ignore();
        is >> m_mon;
        is.ignore();
        is >> m_day;
        if (is.fail()) {
            errCode(Cin_Failed);
            is.clear();
        }
        else {
            if (m_year >= MIN_YEAR && m_year <= currentYear()) {
                if (m_mon >= 1 && m_mon <= 12) {
                    if (m_day <= mdays() && m_day >= 1)
                        errCode(No_Errors_Caught);
                    else errCode(Wrong_Day);
                }
                else
                    errCode(Wrong_Month);
            }
            else
                errCode(Wrong_Year);
        }
        return is;
    }

    std::ostream& Date::write(std::ostream& os) const {
        if (this->bad()) {
            os << dateStatus();
        } 
        else {
            os << m_year;

            os << "/";

            os << right << setw(2) << setfill('0') << m_mon;

            os << "/";

            os << right << setw(2) << setfill('0') << m_day;
            os << setfill(' ');

        }
        return os;

    }

    bool Date::operator == (const Date& right) const {
        if (this->m_day == right.m_day)
            if (this->m_mon == right.m_mon)
                if (this->m_year == right.m_year)
                    return true;
        return false;
    }

    bool Date::operator != (const Date& right) const {
        return (this->m_year != right.m_year ||
            this->m_mon != right.m_mon ||
            this->m_day != right.m_day);
    }

    bool Date::operator >= (const Date& right) const {
        if (this->m_day >= right.m_day)
            if (this->m_mon >= right.m_mon)
                if (this->m_year >= right.m_year)
                    return true;
        return false;
    }

    bool Date::operator <= (const Date& right) const {
        if (this->m_day <= right.m_day)
            if (this->m_mon <= right.m_mon)
                if (this->m_year <= right.m_year)
                    return true;
        return false;
    }

    bool Date::operator < (const Date& right) const {
        return (this->m_year < right.m_year ||
            this->m_mon < right.m_mon ||
            this->m_day < right.m_day);
    }

    bool Date::operator > (const Date& right) const {
        return (this->m_year > right.m_year ||
            this->m_mon > right.m_mon ||
            this->m_day > right.m_day);
    }

    int Date::operator - (const Date& right) const {
        return (daysSince0001_1_1() - right.daysSince0001_1_1());
    }

    Date::operator bool() const {
        return (m_year >= 1500 && m_year <= m_CUR_YEAR &&
            m_mon >= 1 && m_mon <= 12 &&
            m_day >= 1 && m_day <= mdays());
    }
}

