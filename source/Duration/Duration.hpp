#ifndef DURATION_HPP
#define DURATION_HPP

// C++ libs
#include <iostream>
//C libs
#include <ctime>

class Duration {
    public:
        Duration(void);
        void start(void);
        void end(void);
        void display(void);
    protected:
        double m_time_at_start;
        double m_duration;
};

Duration::Duration(void):
    m_time_at_start(0),
    m_duration(0)
{
    //
}

void Duration::start(void) {
    m_time_at_start = time(nullptr);
}

void Duration::end(void) {
    m_duration = time(nullptr) - m_time_at_start;
}

void Duration::display(void) {
    std::cout << "Time since start: " << m_duration << "s" << std::endl;
    if (m_duration >= 60)
        std::cout << " -in minutes: " << m_duration / 60.0 << "min" << std::endl;
    if (m_duration >= 3600)
        std::cout << " -in hours: " << m_duration / 3600.0 << "h" << std::endl;
}

#endif /* DURATION_HPP */
