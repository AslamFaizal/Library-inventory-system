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
#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__

#include"Publication.h"
#include"Book.h"
#include"Menu.h"
#include"Lib.h"

namespace sdds {
	class LibApp {
	private:
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char file_name[256];

		Publication* PPA[SDDS_LIBRARY_CAPACITY];
		int NOLP;
		int LLRN;

		Menu m_pubMenu;
		bool confirm(const char* message);
		void load();  
		void save();  
		int search(int version);
		void returnPub(); 

	public:
		LibApp(const char*);
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
		Publication* getPub(int libRef);
		~LibApp();
	};
}
#endif 