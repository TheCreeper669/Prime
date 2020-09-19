#ifndef SCP_TIME_PROGRESSBAR_HPP
#define SCP_TIME_PROGRESSBAR_HPP

// C++ std
#include <iostream>

namespace scp {
namespace time {

class ProgressBar {
	public:
		ProgressBar(void);
		ProgressBar(std::size_t char_per_line, std::size_t total_char);
		void set(std::size_t char_per_line, std::size_t total_char);
		void reset_ratio(void);
		void display_start(void);
		void actualize_display(std::size_t current, std::size_t total);
		void display_end(void);
	protected:
		std::size_t m_char_per_line;
		std::size_t m_total_char;
		std::size_t m_char_to_display;
		std::size_t m_displayed_char;
};

ProgressBar::ProgressBar(void):
	m_char_per_line(0),
	m_total_char(0),
	m_char_to_display(0),
	m_displayed_char(0)
{
	//
}

ProgressBar::ProgressBar(std::size_t char_per_line, std::size_t total_char):
	m_char_per_line(char_per_line),
	m_total_char(total_char),
	m_char_to_display(0),
	m_displayed_char(0)
{
	//
}

void ProgressBar::set(std::size_t char_per_line, std::size_t total_char) {
	m_char_per_line = char_per_line;
	m_total_char = total_char;
}

void ProgressBar::reset_ratio(void) {
	m_char_to_display = 0;
	m_displayed_char = 0;
}

void ProgressBar::display_start(void) {
	std::cout
		<< "|" << std::string(m_char_per_line, '-') << "| " << m_total_char / m_char_per_line << std::endl
		<< "|" << std::flush
	;
}

void ProgressBar::actualize_display(std::size_t current, std::size_t total) {
	m_char_to_display = static_cast<std::size_t>(static_cast<double>(current) / static_cast<double>(total) * m_total_char);
	if (m_char_to_display > m_displayed_char) {
		std::cout << "=" << std::flush;
		++m_displayed_char;
		if (m_displayed_char % m_char_per_line == 0) {
			std::cout << "| " << m_displayed_char / m_char_per_line << " / " << m_total_char / m_char_per_line << std::endl;
			if (m_displayed_char != m_total_char)
					std::cout << "|" << std::flush;
		}
	}
}

void ProgressBar::display_end(void) {
	m_char_to_display = m_total_char;
	while (m_char_to_display > m_displayed_char) {
		std::cout << '=';
		++m_displayed_char;
		if (m_displayed_char % m_char_per_line == 0) {
			std::cout << "| " << m_displayed_char / m_char_per_line << " / " << m_total_char / m_char_per_line << std::endl;
			if (m_displayed_char != m_total_char)
				std::cout << "|" << std::flush;
		}
	}
}

}} // namespaces

#endif // SCP_TIME_PROGRESSBAR_HPP
