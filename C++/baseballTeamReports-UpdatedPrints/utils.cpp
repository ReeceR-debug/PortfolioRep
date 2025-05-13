// utils.cpp
// Purpose: Implementation of utility functions, including trimRight.

#include "utils.h"
#include <cctype>

string trimRight(const string& str) {
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}
