#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <string>
#include <cctype>
#include <algorithm>

// Функция для приведения строки к нижнему регистру
std::string toLower(const std::string& str);

// Функция для чтения слов из файла и подсчета их количества
void processFile(const std::string& filename, std::unordered_map<std::string, int>& wordCount, std::set <std::string>& uniqueWords);

#endif // FUNCTIONS_HPP