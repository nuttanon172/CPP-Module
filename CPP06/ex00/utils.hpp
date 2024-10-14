#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#define NONDISPLAY 1
#define IMPOSSIBLE 0

void isCorrect(char *av);
void printChar(double &d, bool &impossible);
void printInt(double &d, bool &impossible);
void printFloat(double &d);
void printDouble(double &d);
std::string strError(bool err);

#endif
