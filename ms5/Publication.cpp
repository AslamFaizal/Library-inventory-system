/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 5   *****************************

#define _CRT_SECURE_NO_WARNINGS
#include"Publication.h"
#include <ios>
#include<iomanip>
#include<cstring>
#include<string.h>

namespace sdds {
	Publication::Publication() :m_date() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

	}
	Publication::Publication(const Publication& other) {
		if (other.m_title != nullptr) {
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
		else
			m_title = nullptr;
		strcpy(m_shelfId, other.m_shelfId);
		m_membership = other.m_membership;
		m_date = other.m_date;
		m_libRef = other.m_libRef;
	}
	Publication& Publication::operator=(const Publication& other)
	{
		if (m_title != nullptr) {
			delete[] m_title;
		}
		if (other.m_title != nullptr) {
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
		else
			m_title = nullptr;
		strcpy(m_shelfId, other.m_shelfId);
		m_membership = other.m_membership;
		m_date = other.m_date;
		m_libRef = other.m_libRef;
		return *this;
	}
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date.setToToday();
	}
	char Publication::type() const
	{
		return 'P';
	}
	bool Publication::onLoan() const
	{
		return m_membership != 0;

	}
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title) != nullptr;
	}
	Publication::operator const char* () const
	{
		if (m_title != nullptr)
			return m_title;
		else
			return "";
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	bool Publication::conIO(ios& io) const
	{
		return (&io == &cin || &io == &cout);
	}
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (conIO(os)) {
			os << "| " << m_shelfId << " | ";
			string str = m_title;
			if (strlen(m_title) > SDDS_TITLE_WIDTH) {
				os << str.substr(0, SDDS_TITLE_WIDTH);
			}
			else {
				os << setw(30) << setfill('.') << left << m_title;
			}

			os << right << " | ";

			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | " << m_date << " |";
		}
		else {
			os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
				<< m_title << '\t' << m_membership << '\t' << m_date;
		}
		return os;
	}
	std::istream& Publication::read(std::istream& istr)
	{
		if (m_title != nullptr)
			delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();

		char title[100], shelfID[100];
		Date date;
		int libref = -1, membership = 0;
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr >> shelfID;
			if (strlen(shelfID) != SDDS_SHELF_ID_LEN) {
				istr.setstate(std::ios::failbit);
				cout << "Title: ";
				cout << "Date: ";
			}
			else {
				cout << "Title: ";
				istr.clear();
				istr.ignore(1000, '\n');
				istr.getline(title, 100, '\n');
				cout << "Date: ";
				date.read(istr);
			}
		}
		else {
			istr >> libref;
			istr.ignore();
			istr >> shelfID;
			istr.ignore();
			istr.getline(title, 100, '\t');
			istr >> membership;
			istr.ignore();
			date.read(istr);
		}
		if (date.errCode() != 0) {
			istr.setstate(std::ios::failbit);
		}
		if (!istr.fail()) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfID);
			m_membership = membership;
			m_date = date;
			m_libRef = libref;
		}
		return istr;
	}
	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}

	Publication::~Publication()
	{
		if (m_title != nullptr) {
			delete[] m_title;
		}
	}


	std::ostream& operator<<(std::ostream& os, const Publication& pub)
	{
		if ((bool)pub)
			return pub.write(os);
		else {
			return os;
		}
	}

	std::istream& operator>>(std::istream& is, Publication& pub)
	{
		return pub.read(is);
	}

}
