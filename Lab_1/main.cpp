#include <iostream>
#include "lab1_header.h"

int main(int argc, char* argv[]) {
	std::string cpp_filename_1 = "cpp_first.txt", cpp_filename_2 = "cpp_second.txt";
	char c_filename_1[] = "c_first.txt";
	char c_filename_2[] = "c_second.txt";

	if ((argc == 3) && strcmp(argv[2], "FileStream") == 0) {
		cpp_functions_caller(cpp_filename_1, cpp_filename_2);
	}
	else if((argc == 3) && strcmp(argv[2], "FilePointer") == 0) {
		c_functions_caller(c_filename_1, c_filename_2);
	}
	return 0;
}
