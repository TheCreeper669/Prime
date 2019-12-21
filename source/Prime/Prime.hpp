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

namespace scp {
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
            scp::List<uint64_t> list;
            scp::Duration d;
            //
            d.start();
            std::cout << std::endl;
            std::cout << "Computing " << number << " primes..." << std::endl;
            list.push_back(2);
            list.push_back(3);
            bool _4 = false;
            scp::Item<uint64_t>* inTest = &list.back();
            scp::Item<uint64_t>* current;
            while (list.size() <= number) {
                current = &list.front();
                for (uint64_t i = 1; i < list.size(); i++) {
                    if (inTest->data() % current->data() == 0)
                        break;
                    if (current->data() * current->data() > inTest->data())
                        break;
                    current = &current->next();
                }
                if (inTest->data() % current->data() != 0) {
                    list.push_back(inTest->data());
                    inTest = &list.back();
                }
                if (_4)
                    inTest->data() += 4;
                else
                    inTest->data() += 2;
            }
            list.pop_back();
            d.end();
            d.display();
            //
            d.start();
            std::cout << std::endl;
            std::cout << "Writing " << number << " primes..." << std::endl;
            for (uint64_t i = 0; list.size() > 0; i++)
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
            scp::List<uint64_t> list;
            scp::Duration duration;
            scp::ProgressBar progressBar(char_per_line, total_char);
            //
            duration.start();
            std::cout << std::endl;
            std::cout << "Computing " << number << " primes :" << std::endl;
            progressBar.reset_ratio();
            progressBar.display_start();
            list.push_back(2);
            list.push_back(3);
            bool _4 = false;
            scp::Item<uint64_t>* inTest = &list.back();
            scp::Item<uint64_t>* current;
            while (list.size() <= number) {
                current = &list.front();
                for (uint64_t i = 1; i < list.size(); i++) {
                    if (inTest->data() % current->data() == 0)
                        break;
                    if (current->data() * current->data() > inTest->data())
                        break;
                    current = &current->next();
                }
                if (inTest->data() % current->data() != 0) {
                    list.push_back(inTest->data());
                    inTest = &list.back();
                    progressBar.actualize_display(list.size(), number);
                }
                if (_4)
                    inTest->data() += 4;
                else
                    inTest->data() += 2;
            }
            list.pop_back();
            progressBar.display_end();
            duration.end();
            duration.display();
            //
            duration.start();
            std::cout << std::endl;
            std::cout << "Writing " << number << " primes :" << std::endl;
            progressBar.reset_ratio();
            progressBar.display_start();
            for (uint64_t i = 0; list.size() > 0; i++) {
                file << list.pop_front() << std::endl;
                progressBar.actualize_display(i, number);
            }
            progressBar.display_end();
            duration.end();
            duration.display();
        }
    }
}

#endif /* PRIME_HPP */
