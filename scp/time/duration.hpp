#ifndef SCP_TIME_DURATION_HPP
#define SCP_TIME_DURATION_HPP

// C++ libs
#include <iostream>
#include <chrono>

namespace scp {
namespace time {

class Duration {
    public:
        Duration(void);
        ~Duration(void);
    protected:
        std::chrono::high_resolution_clock::time_point m_time_at_start;
};

Duration::Duration(void) {
    m_time_at_start = std::chrono::high_resolution_clock::now();
}

Duration::~Duration(void) {
    std::chrono::high_resolution_clock::duration duration = std::chrono::high_resolution_clock::now() - m_time_at_start;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() << "ns" << std::endl;
    if (std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() >= 1000)
        std::cout << "      or: " << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << "µs" << std::endl;
    if (std::chrono::duration_cast<std::chrono::microseconds>(duration).count() >= 1000)
        std::cout << "      or: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms" << std::endl;
    if (std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() >= 1000)
        std::cout << "      or: " << std::chrono::duration_cast<std::chrono::seconds>(duration).count() << "s" << std::endl;
    if (std::chrono::duration_cast<std::chrono::seconds>(duration).count() >= 60)
        std::cout << "      or: " << std::chrono::duration_cast<std::chrono::minutes>(duration).count() << "min" << std::endl;
    if (std::chrono::duration_cast<std::chrono::minutes>(duration).count() >= 60)
        std::cout << "      or: " << std::chrono::duration_cast<std::chrono::hours>(duration).count() << "h" << std::endl;
}

}} // closing namespace scp::time

#endif /* SCP_TIME_DURATION_HPP */
