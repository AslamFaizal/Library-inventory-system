
#include <iostream>
#include<iomanip>
#include<cstring>

#include "Utils.h"

using namespace std;
namespace sdds {
	unsigned int getIntInRange(int Min, int Max) {
		int i;
		cin >> i;
		if (cin.fail() || i<Min || i>Max) {
			cin.clear();
			char ch;
			while (cin.get(ch) && ch != '\n') {
				;
			}
			cout << "Invalid Selection, try again: ";
			return getIntInRange(Min, Max);
		}
		else {
			return i;
		}
	}
}