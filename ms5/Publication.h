/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 5   *****************************


#pragma once
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include<iostream>
#include"Lib.h"
#include"Date.h"
#include"Streamable.h"
using namespace std;
namespace sdds {
	class Publication :public Streamable {
	private:
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		Publication& operator = (const Publication&);
		Publication(const Publication&);
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		ostream& write(ostream&)const;
		istream& read(istream&);
		bool conIO(ios&)const;
		operator bool()const;
		virtual ~Publication();
	};
	std::ostream& operator<<(std::ostream& os, const Publication& pub);
	std::istream& operator>>(std::istream& is, Publication& pub);
}
#endif