
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
#include<cstring>
#include<string>
#include<ctype.h>


#include "Utils.h"

using namespace std;

namespace sdds {

    void Utils::getChar(std::istream& is, char Ch) {
        if (is.peek() == Ch) is.get();
    }

    void Utils::getChar(std::istream& is) {
        if (isdigit(is.peek())) {
            is.setstate(ios::failbit);
        }
        else {
            is.get();
        }
    }

    int Utils::getInt(std::istream& is, int Min, int Max,
        const char* message) {
        int res = 0;
        bool flag = false;
        while (!flag) {
            is >> res;
            if (is && is.peek() == '\n') {
                if (res >= Min && res <= Max) {
                    flag = true;
                }
                else {
                    is.ignore(1000, '\n');
                    cout << "Out of Range, try again: ";
                }
            }
            else {
                is.clear();
                is.ignore(1000, '\n');
                if (message) cout << message;
            }
        }
        return res;
    }

    void Utils::copyStr(char*& Desc,
        const char* src) {
        delete[] Desc;
        Desc = new char[strlen(src) + 1];
        strcpy(Desc, src);
    }

    char* Utils::readInput(istream& is, char delimeter) {
        char* str{};
        string toRead;
        getline(is, toRead, delimeter);
        if (is) {
            str = new char[strlen(toRead.c_str()) + 1];
            strcpy(str, toRead.c_str());
        }
        return str;
    }
}

