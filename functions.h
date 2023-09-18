#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Functions {
public:
	std::vector<string> sortBooks(std::vector<string> &);
};

std::vector<string> Functions::sortBooks(std::vector<string> &bookList){
    sort(bookList.begin(), bookList.end());
   return bookList;
};

#endif /* FUNCTIONS_H_ */

