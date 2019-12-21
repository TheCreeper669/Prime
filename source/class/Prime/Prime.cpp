#include "Prime.hpp"

namespace prime {
    void calc(const std::string& filePath, const long long& number) {
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
        List<unsigned long long> list;
        //
        std::time_t start = std::time(nullptr);
        std::cout << std::endl;
        std::cout << "Computing " << number << " primes..." << std::endl;
        list.push_back(2);
        uint64_t inTest = 3;
        while (list.get_size() < number) {
            list.cursorDefault();
            for (unsigned long i = 0; inTest % list.cursorData() != 0 && i < list.get_size() && list.cursorData() * list.cursorData() <= inTest; i++) {
                list.cursorFront();
            }
            if (inTest % list.cursorData() != 0) {
                list.push_back(inTest);
                inTest += 2;
            }else{
                inTest += 2;
            }
        }
        std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
        start = std::time(nullptr);
        //
        std::cout << std::endl;
        std::cout << "Writing " << number << " primes..." << std::endl;
        for (unsigned long i = 0; list.get_size() > 0; i++) {
            file << list.pop_front() << std::endl;
        }
        std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
    }

    void calc(const std::string& filePath, const long long& number, const int& RATIO_PER_LINE, const double& RATIO_TOTAL) {
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
        List<unsigned long long> list;
        //
        std::time_t start = std::time(nullptr);
        std::cout << std::endl;
        std::cout << "Computing " << number << " primes :" << std::endl;
        std::cout << "|";
        for (int i = 0; i < RATIO_PER_LINE; i++) {
            std::cout << "-";
        }
        std::cout << "|" << std::endl;
        std::cout << "|";
        int ratio = 0;
        int printedRatio = 0;
        list.push_back(2);
        uint64_t inTest = 3;
        while (list.get_size() < number) {
            list.cursorDefault();
            for (unsigned long i = 0; inTest % list.cursorData() != 0 && i < list.get_size() && list.cursorData() * list.cursorData() <= inTest; i++) {
                list.cursorFront();
            }
            if (inTest % list.cursorData() != 0) {
                list.push_back(inTest);
                ratio = static_cast<int>((static_cast<double>(list.get_size()) / static_cast<double>(number)) * RATIO_TOTAL);
                while (ratio >= printedRatio + 1) {
                    std::cout << "=";
                    printedRatio++;
                    if (printedRatio % RATIO_PER_LINE == 0) {
                        std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
                    }
                }
                inTest += 2;
            }else{
                inTest += 2;
            }
        }
        ratio = static_cast<int>((static_cast<double>(list.get_size()) / static_cast<double>(number)) * RATIO_TOTAL);
        while (ratio >= printedRatio + 1) {
            std::cout << "=";
            printedRatio++;
            if (printedRatio % RATIO_PER_LINE == 0) {
                std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
            }
        }
        for (int i = 0; i < RATIO_PER_LINE; i++) {
            std::cout << "-";
        }
        std::cout << "|" << std::endl;
        std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
        start = std::time(nullptr);
        //
        std::cout << std::endl;
        std::cout << "Writing " << number << " primes :" << std::endl;
        std::cout << "|";
        for (int i = 0; i < RATIO_PER_LINE; i++) {
            std::cout << "-";
        }
        std::cout << "|" << std::endl;
        std::cout << "|";
        ratio = 0;
        printedRatio = 0;
        double originalSize = static_cast<double>(list.get_size());
        for (unsigned long i = 0; list.get_size() > 0; i++) {
            ratio = static_cast<int>((static_cast<double>(i + 1) / originalSize) * RATIO_TOTAL);
            while (ratio >= printedRatio + 1) {
                std::cout << "=";
                printedRatio++;
                if (printedRatio % RATIO_PER_LINE == 0) {
                    std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
                }
            }
            file << list.pop_front() << std::endl;
        }
        ratio = static_cast<int>((1.0 / originalSize) * RATIO_TOTAL);
        while (ratio >= printedRatio + 1) {
            std::cout << "=";
            printedRatio++;
            if (printedRatio % RATIO_PER_LINE == 0) {
                std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
            }
        }
        for (int i = 0; i < RATIO_PER_LINE; i++) {
            std::cout << "-";
        }
        std::cout << "|" << std::endl;
        std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
    }
}
