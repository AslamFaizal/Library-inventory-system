
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 3  *****************************


#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include <iostream>
#include<iomanip>
#include<cstring>
 
namespace sdds {         
    //using external data type from according to the instruction
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;

    const int No_Errors_Caught = 0;
    const int Cin_Failed = 1;
    const int Wrong_Year =  2;
    const int Wrong_Month = 3;
    const int Wrong_Day = 4;
    const char Errors_in_Date[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
    };

    const int MIN_YEAR = 1500;

    class Date {      //Decalaring a Class named Date

    private:      //Claffying these function as Private
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1() const; 
        bool validate();
        void errCode(int);
        int systemYear() const; 
        bool bad() const; 
        int mdays() const; 
        void setToToday(); 

        friend class Publication;     //Adding a frined class named Publication

    public:           //Classifying these fucntion as public
        Date(); 
        Date(int year, int mon, int day);
        int errCode() const; 
        const char* dateStatus() const; 
        int currentYear() const; 
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        
        bool operator == (const Date& right) const;
        bool operator != (const Date& right) const;
        bool operator >= (const Date& right) const;
        bool operator <= (const Date& right) const;
        bool operator < (const Date& right) const;
        bool operator > (const Date& right) const;
        
        int operator - (const Date& right) const;
        
        operator bool() const;
    };

    std::ostream& operator << (std::ostream& os,
        const Date& RoundOff);
    std::istream& operator >> (std::istream& is, Date& RoundOff);
}
#endif
