#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>


void printSet(const std::string& header, const std::set<std::string>& s, std::ostream& os);
void checkFile(std::ofstream& fin);

#endif // FUNCTIONS_HPP