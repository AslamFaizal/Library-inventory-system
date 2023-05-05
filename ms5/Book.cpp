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

#include<iostream>
#include<iomanip>
#include<string.h>

#include"Book.h"

using namespace std;
namespace sdds {
	Book::Book() :Publication() {
		authorName = nullptr;
	}

	Book::Book(const Book& book) : Publication(book) {
		authorName = nullptr;
		if (book.authorName != nullptr) {
			authorName = new char[strlen(book.authorName) + 1];
			strcpy(authorName, book.authorName);
		}
	}

	Book& Book::operator=(const Book& book)
	{
		this->Publication::operator=(book);
		if (authorName != nullptr)
			delete[] authorName;
		authorName = nullptr;
		if (book.authorName != nullptr) {
			authorName = new char[strlen(book.authorName) + 1];
			strcpy(authorName, book.authorName);
		}
		return *this;
	}

	char Book::type() const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			os << " ";
			string str = authorName;
			if (strlen(authorName) > SDDS_AUTHOR_WIDTH) {
				os << str.substr(0, SDDS_AUTHOR_WIDTH);
			}
			else {
				os << left << setw(SDDS_AUTHOR_WIDTH) << authorName;
			}
			os << " |";
		}
		else {
			os << "\t" << authorName;
		}
		return os;
	}

	istream& Book::read(istream& is)
	{
		Publication::read(is);
		if (authorName != nullptr)
			delete[] authorName;
		authorName = nullptr;
		char author[257];
		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.getline(author, 250);
		}
		else {
			is.ignore();
			is.get(author, 250, '\n');
		}

		if (!is.fail()) {
			authorName = new char[strlen(author) + 1];
			strcpy(authorName, author);
		}
		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const
	{
		return (this->Publication::operator bool() && authorName != nullptr);
	}

	Book::~Book()
	{
		if (authorName != nullptr) {
			delete[] authorName;
		}
	}
}