#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <iostream>

class ProgressBar {
    public:
        ProgressBar(void);
        ProgressBar(const int& char_per_line, const int& total_char);
        void set(const int& char_per_line, const int& total_char);
        void reset_ratio(void);
        void display_start(void);
        void actualize_display(const uint64_t& current, const uint64_t& total);
        void display_end(void);
    protected:
        int m_char_per_line;
        int m_total_char;
        int m_char_to_display;
        int m_displayed_char;
};

ProgressBar::ProgressBar(void):
    m_char_per_line(0),
    m_total_char(0),
    m_char_to_display(0),
    m_displayed_char(0)
{
    //
}

ProgressBar::ProgressBar(const int& char_per_line, const int& total_char):
    m_char_per_line(char_per_line),
    m_total_char(total_char),
    m_char_to_display(0),
    m_displayed_char(0)
{
    //
}

void ProgressBar::set(const int& char_per_line, const int& total_char) {
    m_char_per_line = char_per_line;
    m_total_char = total_char;
}

void ProgressBar::reset_ratio(void) {
    m_char_to_display = 0;
    m_displayed_char = 0;
}

void ProgressBar::display_start(void) {
    std::cout << "|";
    for (int i = 0; i < m_char_per_line; i++)
        std::cout << "-";
    std::cout << "| " << m_total_char / m_char_per_line << std::endl;
    std::cout << "|";
}

void ProgressBar::actualize_display(const uint64_t& current, const uint64_t& total) {
    m_char_to_display = static_cast<int>((static_cast<double>(current) / static_cast<double>(total)) * m_total_char);
    while (m_char_to_display > m_displayed_char) {
        std::cout << "=";
        m_displayed_char++;
        if (m_displayed_char % m_char_per_line == 0)
            std::cout << "| " << m_displayed_char / m_char_per_line << " / " << m_total_char / m_char_per_line << std::endl << "|";
    }
}

void ProgressBar::display_end(void) {
    m_char_to_display = m_total_char;
    while (m_char_to_display > m_displayed_char) {
        std::cout << "=";
        m_displayed_char++;
        if (m_displayed_char % m_char_per_line == 0)
            std::cout << "| " << m_displayed_char / m_char_per_line << " / " << m_total_char / m_char_per_line << std::endl << "|";
    }
    for (int i = 0; i < m_char_per_line; i++)
        std::cout << "-";
    std::cout << "|" << std::endl;
}

#endif /* PROGRESSBAR_HPP */
