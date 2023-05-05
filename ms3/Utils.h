
/*CITATION:-

NAME:- FAIZAL ASLAM
STUDENT ID:- 152121216
SECTION:- OOP244ZBB
DATE:- 2022-07-29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

//***********************  MILESTONE - 3  *****************************


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

using namespace std;

namespace sdds {
    class Utils {
    public:
        Utils() = delete;
        static void getChar(std::istream& is, char Ch); 
        static void getChar(std::istream& is); 
        static int getInt(std::istream& is, int Min, int Max,
            const char*
            message = nullptr); 
        static void copyStr(char*& Desc,
            const char* src);
        static char* readInput(std::istream& is, char delimeter = '\n'); 
    };
}
#endif 

