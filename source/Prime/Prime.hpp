#ifndef PRIME_HPP
#define PRIME_HPP

// C++ libs
#include <iostream>
#include <fstream>
#include <string>
// C libs
#include <cstdlib>
// my libs
#include "../List/List.hpp"
#include "../Duration/Duration.hpp"
#include "../ProgressBar/ProgressBar.hpp"

namespace prime{
    void calc(const std::string& filePath, const uint64_t& number) {
        std::fstream file;
        file.open(filePath, std::ios_base::out | std::ios_base::trunc);
        if (file.is_open()) {
            std::cout << std::endl;
            std::cout << "|------------------------|" << std::endl;
            std::cout << "|File opened successfully|" << std::endl;
            std::cout << "|------------------------|" << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << "|-------------------|" << std::endl;
            std::cout << "|File failed to open|" << std::endl;
            std::cout << "|-------------------|" << std::endl;
        }
        //
        List<uint64_t> list;
        Duration d;
        //
        d.start();
        std::cout << std::endl;
        std::cout << "Computing " << number << " primes..." << std::endl;
        if (number > 0)
            list.push_back(2);
        uint64_t inTest = 3;
        while (list.get_size() < number) {
            list.cursorDefault();
            for (uint64_t i = 0; i < list.get_size(); i++) {
                if (inTest % list.cursorData() == 0)
                    break;
                if (list.cursorData() * list.cursorData() > inTest)
                    break;
                list.cursorFront();
            }
            if (inTest % list.cursorData() != 0)
                list.push_back(inTest);
            inTest += 2;
        }
        d.end();
        d.display();
        //
        d.start();
        std::cout << std::endl;
        std::cout << "Writing " << number << " primes..." << std::endl;
        for (unsigned long i = 0; list.get_size() > 0; i++)
            file << list.pop_front() << std::endl;
        d.end();
        d.display();
    }
    //
    void calc(const std::string& filePath, const uint64_t& number, const int& char_per_line, const int& total_char) {
        std::fstream file;
        file.open(filePath, std::ios_base::out | std::ios_base::trunc);
        if (file.is_open()) {
            std::cout << std::endl;
            std::cout << "|------------------------|" << std::endl;
            std::cout << "|File opened successfully|" << std::endl;
            std::cout << "|------------------------|" << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << "|-------------------|" << std::endl;
            std::cout << "|File failed to open|" << std::endl;
            std::cout << "|-------------------|" << std::endl;
        }
        //
        List<uint64_t> list;
        Duration d;
        ProgressBar pb(char_per_line, total_char);
        //
        d.start();
        std::cout << std::endl;
        std::cout << "Computing " << number << " primes :" << std::endl;
        pb.reset_ratio();
        pb.display_start();
        if (number > 0)
            list.push_back(2);
        uint64_t inTest = 3;
        while (list.get_size() < number) {
            list.cursorDefault();
            for (uint64_t i = 0; i < list.get_size(); i++) {
                if (inTest % list.cursorData() == 0)
                    break;
                if (list.cursorData() * list.cursorData() > inTest)
                    break;
                list.cursorFront();
            }
            if (inTest % list.cursorData() != 0) {
                list.push_back(inTest);
                pb.actualize_display(list.get_size(), number);
            }
            inTest += 2;
        }
        pb.display_end();
        d.end();
        d.display();
        //
        d.start();
        std::cout << std::endl;
        std::cout << "Writing " << number << " primes :" << std::endl;
        pb.reset_ratio();
        pb.display_start();
        for (uint64_t i = 0; list.get_size() > 0; i++) {
            file << list.pop_front() << std::endl;
            pb.actualize_display(i, number);
        }
        pb.display_end();
        d.end();
        d.display();
    }
};

#endif /* PRIME_HPP */
