#ifndef PRIME_HPP
#define PRIME_HPP

// C++
#include <iostream>
#include <fstream>
#include <string>
// C
#include <cstdlib>
#include <ctime>
//mine
#include "../List/List.hpp"

namespace prime{
        void calc(const std::string& filePath, const long long& number);
        void calc(const std::string& filePath, const long long& number, const int& RATIO_PER_LINE, const double& RATIO_TOTAL);
};

#endif /* PRIME_HPP */
