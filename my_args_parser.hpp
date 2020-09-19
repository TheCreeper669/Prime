#ifndef MY_ARGS_PARSER_HPP
#define MY_ARGS_PARSER_HPP

// C++ std
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <exception>

// C std
#include <cstdlib>

// scp
#include <scp/args_parser.hpp>


class MyArgsParser: public scp::ArgsParser {
public:
	MyArgsParser(int argc = 0, const char* argv[] = nullptr, const std::unordered_set<std::size_t>& solvable_problems = {});
	~MyArgsParser(void) override = default;

	std::string filename;
	std::size_t number;
	std::size_t char_per_line;
	std::size_t number_line;
	bool debug;
	bool verbose;
};


MyArgsParser::MyArgsParser(int argc, const char* argv[], const std::unordered_set<std::size_t>& solvable_problems):
	scp::ArgsParser(argc, argv),
	filename("default"),
	number(1000),
	char_per_line(0),
	number_line(1),
	debug(false),
	verbose(false)
{
	if (m_args_map.count("h") == 1 || m_args_map.count("help") == 1) {
		std::cout
			<< "Usage:" << std::endl
			<< "  [-f <filename='default'> string]: filename to put primes in." << std::endl
			<< "  [-n <number=1000> {1:}]: number of primers to compute." << std::endl
			<< "  [-l <char_per_line=0>:<number_line=1> {1:}[:{1:}]]: number of line and characters per line in loading bars." << std::endl
			<< "  [-h --help]: display this help message." << std::endl
			<< "  [-v --verbose]: verbose mode." << std::endl
			<< "  [-d --debug]: debug mode." << std::endl
			<< std::endl
		;
		std::exit(EXIT_SUCCESS);
	}

	if (m_args_map.count("d") == 1 || m_args_map.count("debug") == 1)
		debug = true;

	if (m_args_map.count("v") == 1 || m_args_map.count("verbose") == 1)
		verbose = true;

	if (m_args_map.count("f"))
		filename = m_args_map["f"];

	if (m_args_map.count("n"))
		number = parse_size_t(m_args_map["n"], "number");

	if (m_args_map.count("l")) {
		std::string::size_type index = m_args_map["l"].find(':');
		if (index != std::string::npos) {
			char_per_line = parse_size_t(m_args_map["l"].substr(0, index), "char_per_line");
			number_line = parse_size_t(m_args_map["l"].substr(index + 1), "number_line");
		} else {
			char_per_line = parse_size_t(m_args_map["l"], "char_per_line");
		}
	}

	if (debug) {
		std::cout << "m_args_map: {" << std::endl;
		for (const auto& arg: m_args_map)
			std::cout << "'" << arg.first << "': '" << arg.second << "'," << std::endl;
		std::cout << "}" << std::endl << std::endl;

		std::cout << "m_args_set: { ";
		for (const auto& arg: m_args_set)
			std::cout << "'" << arg << "', ";
		std::cout << "}" << std::endl << std::endl;

		std::cout
			<< "debug: " << (debug ? "true" : "false") << std::endl
			<< "verbose: " << (verbose ? "true" : "false") << std::endl
			<< "filename: '" << filename << "'" << std::endl
			<< "number: " << number << std::endl
			<< "char_per_line: " << char_per_line << std::endl
			<< "number_line: " << number_line << std::endl
			<< std::endl
		;
	}
}


#endif // MY_ARGS_PARSER_HPP