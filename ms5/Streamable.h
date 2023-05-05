
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-08-06
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 4  *****************************

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include<iostream>
using namespace std;
namespace sdds {
	class Streamable {
	public:
		virtual ostream& write(ostream&)const = 0;
		virtual istream& read(istream&) = 0;
		virtual bool conIO(ios&)const = 0;
		virtual operator bool()const = 0;
		~Streamable() {};
	};
}
#endif
