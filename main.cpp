// scp
#include <scp/prime.hpp>

// project
#include "my_args_parser.hpp"

int main(int argc, const char* argv[]) {
	auto parser = MyArgsParser(argc, argv);

	if (parser.number_line * parser.char_per_line == 0)
		scp::prime::calc("./prime_" + parser.filename + ".txt", parser.number);
	else
		scp::prime::calc("./prime_" + parser.filename + ".txt", parser.number, parser.char_per_line, parser.char_per_line * parser.number_line);
	
	return EXIT_SUCCESS;
}
