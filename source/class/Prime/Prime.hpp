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

class Prime{
    public:
        //constructor
        Prime(const std::string& filePath);
        //destructor
        ~Prime();
        //static attribute
        //static member
        //member
        void calc(void);
        //friendly operator
        //operator
    protected:
        //attribute
        std::fstream m_file;
        List<unsigned long long> m_dm;
        //member
};

#endif // PRIME_HPP
