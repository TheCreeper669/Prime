#ifndef SCP_PRIME_HPP
#define SCP_PRIME_HPP

// C++ libs
#include <iostream>
#include <fstream>
#include <string>
// scp libs
#include "scp/containers/list.hpp"
#include "scp/time/duration.hpp"
#include "scp/time/progress_bar.hpp"

namespace scp {
namespace prime{

void calc(const std::string& filePath, const uint64_t& number) {
    std::fstream file;
    file.open(filePath, std::ios_base::out | std::ios_base::trunc);
    if (!file.is_open()) {
        std::cout << "|-------------------|" << std::endl;
        std::cout << "|File failed to open|" << std::endl;
        std::cout << "|-------------------|" << std::endl;
        std::cout << std::endl;
        return;
    }
    //
    std::cout << "|------------------------|" << std::endl;
    std::cout << "|File opened successfully|" << std::endl;
    std::cout << "|------------------------|" << std::endl;
    std::cout << std::endl;
    //
    scp::List<uint64_t> list;
    std::cout << "Computing " << number << " primes..." << std::endl;
    {
        scp::time::Duration duration;
        list.push_back(2);
        list.push_back(3);
        scp::list::Item<uint64_t>* inTest = &list.back();
        scp::list::Item<uint64_t>* current;
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
            inTest->data() += 2;
        }
        list.pop_back();
    }
    std::cout << std::endl;
    std::cout << "Writing " << number << " primes..." << std::endl;
    {
        scp::time::Duration duration;
        for (uint64_t i = 0; list.size() > 0; i++)
            file << list.pop_front() << std::endl;
    }
}
//
void calc(const std::string& filePath, const uint64_t& number, const int& char_per_line, const int& total_char) {
    std::fstream file;
    file.open(filePath, std::ios_base::out | std::ios_base::trunc);
    if (!file.is_open()) {
        std::cout << "|-------------------|" << std::endl;
        std::cout << "|File failed to open|" << std::endl;
        std::cout << "|-------------------|" << std::endl;
        std::cout << std::endl;
        return;
    }
    //
    std::cout << "|------------------------|" << std::endl;
    std::cout << "|File opened successfully|" << std::endl;
    std::cout << "|------------------------|" << std::endl;
    std::cout << std::endl;
    //
    scp::List<uint64_t> list;
    scp::time::ProgressBar progressBar(char_per_line, total_char);
    //
    std::cout << "Computing " << number << " primes :" << std::endl;
    progressBar.reset_ratio();
    progressBar.display_start();
    {
        scp::time::Duration duration;
        list.push_back(2);
        list.push_back(3);
        scp::list::Item<uint64_t>* inTest = &list.back();
        scp::list::Item<uint64_t>* current;
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
            inTest->data() += 2;
        }
        list.pop_back();
        progressBar.display_end();
    }
    std::cout << std::endl;
    std::cout << "Writing " << number << " primes :" << std::endl;
    progressBar.reset_ratio();
    progressBar.display_start();
    {
        scp::time::Duration duration;
        for (uint64_t i = 0; list.size() > 0; i++) {
            file << list.pop_front() << std::endl;
            progressBar.actualize_display(i, number);
        }
        progressBar.display_end();
    }
}

}} // closing samespace scp::prime

#endif /* SCP_PRIME_HPP */
