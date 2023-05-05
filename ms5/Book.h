/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 5   *****************************

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include<cstring>
#include<iomanip>

#include"Publication.h"

namespace sdds {
	class Book :public Publication {
	private:
		char* authorName;
	public:
		Book();
		Book(const Book& book);
		Book& operator = (const Book& book);
		char type()const;
		ostream& write(ostream&)const;
		istream& read(istream&);
		void set(int member_id);
		operator bool()const;
		~Book();
	};
}
#endif