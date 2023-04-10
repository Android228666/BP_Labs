#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "lab1_header.h"



//<--------------------- C++ --------------------->

void cpp_write_to_file(std::string filename) {
	std::ofstream input(filename, std::ios::app);
	std::string line = "aaa";

	if (!input) {
		std::cout << "Cannot open file!";
		return;
	}
	std::cout << "Write a few lines of text (last symbol must be '&'):" << std::endl;
	while (line[line.length() - 1] != '&') {
		std::getline(std::cin, line);
		if (line.length() > 1) {
			if (line[line.length() - 1] == '&') {
				std::string temp_line = line;
				temp_line.replace(temp_line.length() - 1, 1, "");
				input << temp_line;
				input << "\n";
			}
			else {
				input << line;
				input << "\n";
			}
		}
		else {
			line = "aaa";
		}
		
	}

	input.close();
}



void cpp_read_file(std::string filename) {
	std::string line;
	std::ifstream output(filename);

	while (!(output.eof())) {
		getline(output, line);
		std::cout << line << std::endl;
	}

	output.close();
}






void cpp_delete_duplicates(std::string filename_1, std::string filename_2) {
	string cpp_most_frequent_element(string);
	void cpp_filling_second_file(string, string);
	std::ofstream temp(filename_2, std::ios::trunc);
	temp.close();
	std::ifstream change(filename_1);
	std::string s;
	int z = 0;
	while (!change.eof()) {
		getline(change, s);
		std::string temp = s;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == ',' || temp[i] == '.') {
				temp.replace(i, 1, " ");
			}
		}
		int word_count = 0;
		std::string c;


		std::stringstream line(temp);
		std::stringstream line1(temp);

		while (line1 >> c) word_count++;

		if (word_count > 1) {
			// need Ineed
			do {
				std::string a;
				while (line >> a) {
					int index = 0, count = 0;
					while (((index = s.find(a, index)) != std::string::npos)) {
						if (((index > 1) &&
							((s[index - 1] == ' ' && s[index + a.length()] == ' ') ||
								(s[index - 1] == ',' && s[index + a.length()] == ',') ||
								(s[index - 1] == '.' && s[index + a.length()] == '.') ||
								(s[index - 1] == ' ' && s[index + a.length()] == '.') ||
								(s[index - 1] == '.' && s[index + a.length()] == ' ') ||
								(s[index - 1] == ' ' && s[index + a.length()] == ',') ||
								(s[index - 1] == ',' && s[index + a.length()] == ' ') ||
								(s[index - 1] == ',' && s[index + a.length()] == '.') ||
								(s[index - 1] == '.' && s[index + a.length()] == ','))) || ((index + a.length()) == s.length()) && (s[index - 1] == ' ' || s[index - 1] == '.' || s[index - 1] == ',') ||
							(index == 0 && (s[index + a.length()] == ' ' || s[index + a.length()] == ',' || s[index + a.length()] == ' '))) {
							count++;
							if ((count > 1)) {
								s.replace(index, a.length(), "");
								z = 1;
							}
						}
						index += 1;

					}
				}

			} while (line);
			std::string done_line;

			//if (s.length() != 0 && z == 1)
			if (s.length() != 0 && z == 1) {
				done_line = cpp_most_frequent_element(s);
				s += done_line;
				cpp_filling_second_file(filename_2, s);
			}

		}
			z = 0;
	}
	change.close();
}



std::string cpp_most_frequent_element(std::string line) {
	std::string result = "";
	int characters[256] = {};
	int max = 0;

	int charIndex = 0;
	for (int i = 0; i < line.length(); i++) {
		int asciiValue = (int)(line[charIndex]);
		characters[asciiValue] += 1;
		charIndex++;
	}

	for (int i = 0; i < 256; i++) {
		if (characters[i] > characters[max]) {
			max = i;
		}
	}

	int count = 0;

	for (int i = 0; i < 256; i++) {
		if (characters[max] == characters[i]) {
			result += " ('";
			result += (char)i;
			result += "' - ";
			result += std::to_string(characters[i]);
			result += ")";
			count++;
			if (count > 0) {
				result += " ";
			}

		}
	}
	return result;
}

void cpp_filling_second_file(std::string filename, std::string text) {
	std::ofstream second(filename, std::ios::app);

	second << text << "\n";

	second.close();

}




void cpp_functions_caller(std::string filename_1, std::string filename_2) {
	cpp_write_to_file(filename_1);
	cpp_delete_duplicates(filename_1, filename_2);
	std::cout << "First file:" << std::endl;
	cpp_read_file(filename_1);
	std::cout << "Second file:" << std::endl;
	cpp_read_file(filename_2);
	cpp_append_data(filename_1, filename_2);
}


void cpp_append_data(std::string filename_1, std::string filename_2) {
	char decision;
	std::cout << "Maybe you want to add anything to your file??? (Y/N)" << std::endl;
	std::cin >> decision;
	if (decision == 'Y') {
		cpp_functions_caller(filename_1, filename_2);
	}
}









//<--------------------- C --------------------->

void write_to_file(char* filename) {
	FILE* write;
	char write_buffer[256] = "Hello";
	fopen_s(&write, filename, "a");

	if (write == NULL) {
		perror("Error: ");

	}
	int len = strlen(write_buffer);
	printf("Write a few lines of text(last symbol must be '&'):\n");
	while (write_buffer[len - 2] != '&') {
		fgets(write_buffer, 256, stdin);
		len = strlen(write_buffer);
		if (strlen(write_buffer) > 1) {
			char temp_buf[256];
			strcpy_s(temp_buf, 256, write_buffer);
			if (write_buffer[len - 2] == '&') {
				temp_buf[len - 2] = temp_buf[len - 1];
				temp_buf[len - 1] = temp_buf[len];
			}
			size_t bytes_wrote = fwrite(temp_buf, sizeof(char), strlen(temp_buf), write);
		}

	}
	fclose(write);
}



void read_file(char* filename) {
	FILE* read;
	char read_buffer[256];
	fopen_s(&read, filename, "r");
	if (read == NULL) {
		perror("Error: ");
	}

	while (fgets(read_buffer, 256, read) != NULL) {
		printf("%s", read_buffer);
	}
	fclose(read);
}




void delete_duplicates(char* filename_1, char* filename_2) {
	char* most_frequent_element(char*);
	FILE* change;
	fopen_s(&change, filename_1, "r");
	if (change == NULL) {
		perror("Error: ");
	}
	char s[256];
	char buf[256];
	int z = 0;
	FILE* temp;
	fopen_s(&temp, filename_2, "w");
	fclose(temp);

	while (fgets(s, 256, change) != NULL) {
		strcpy_s(buf, 256, s);
		char* next_token = NULL;
		const char* divider = " ";
		char* token;

		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == ',' || s[i] == '.') {
				s[i] = ' ';
			}

			if (s[i] == '\n') {
				s[i] = ' ';
			}
		}
		int len = strlen(s);
		for (int i = 0; i < len; i++) {

			if ((i >= 1 && s[i] == ' ' && (s[i + 1] == ' ' || s[i - 1] == ' ')) || (i == 0 && s[i] == ' ')) {
				for (int j = i; j < len; j++) {
					s[j] = s[j + 1];
				}
				len--;
				i--;
			}
		}

		char str[256];
		strcpy_s(str, 256, buf);
		token = strtok_s(s, divider, &next_token);



		int count = 0;
		int len1 = strlen(token);
		len1 = strlen(token);
		char* p = str;
		while (token != NULL) {
			p = str;
			count = 0;
			len1 = strlen(token);
			while ((p = strstr(p, token)) != NULL) {
				if ((((p - str > 0) && ((str[p - str - 1] == ' ' && str[p - str + len1] == ' ') ||
					(str[p - str - 1] == ',' && str[p - str + len1] == ',') ||
					(str[p - str - 1] == '.' && str[p - str + len1] == '.') ||
					(str[p - str - 1] == ',' && str[p - str + len1] == ' ') ||
					(str[p - str - 1] == ' ' && str[p - str + len1] == ',') ||
					(str[p - str - 1] == '.' && str[p - str + len1] == ' ') ||
					(str[p - str - 1] == ' ' && str[p - str + len1] == '.') ||
					(str[p - str - 1] == '.' && str[p - str + len1] == ',') ||
					(str[p - str - 1] == ',' && str[p - str + len1] == '.')))) ||
					((p - str == 0) && (str[len1] == ' ' || str[len1] == ',' || str[len1] == '.')) ||
					(((p - str) + len1) == strlen(str) - 1 && (str[p - str - 1] == ' ' || str[p - str - 1] == ',' || str[p - str - 1] == '.'))) {
					count++;
					if (count > 1) {
						memmove(p, p + len1, strlen(p + len1) + 1);
						z = 1;
					}
				}
				p = p + 1;
			}
			len1 = strlen(token);
			token = strtok_s(NULL, divider, &next_token);
		}


		if (z == 1) {
			FILE* second;
			char* res = most_frequent_element(str);
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == '\n') {
					str[i] = ' ';
				}
			}
			strcat_s(str, sizeof(str), res);
			fopen_s(&second, filename_2, "a");
			fwrite(str, sizeof(char), strlen(str), second);
			fwrite("\n", sizeof(char), strlen("\n"), second);
			fclose(second);
		}


		z = 0;

	}
	fclose(change);
}




char* most_frequent_element(char* line) {
	char result[256];
	int characters[256] = { 0 };
	int max = 0;
	int charIndex = 0;

	for (int charIndex = 0; charIndex < strlen(line); charIndex++) {
		int asciiValue = (int)(line[charIndex]);
		characters[asciiValue] += 1;
	}

	for (int j = 0; j < 256; j++) {
		if (characters[j] > characters[max]) {
			max = j;
		}
	}

	char end_str[256] = "";
	for (int i = 0; i < 256; i++) {
		if (characters[max] == characters[i] && i != 10) {
			sprintf_s(result, 256, "('%c' - %d)", (char)i, characters[max]);
			strcat_s(end_str, sizeof(result), result);
		}
	}
	return end_str;
}

void c_functions_caller(char* filename_1, char* filename_2) {
	write_to_file(filename_1);
	delete_duplicates(filename_1, filename_2);
	printf("First file:\n");
	read_file(filename_1);
	printf("\nSecond file:\n");
	read_file(filename_2);
	append_data(filename_1, filename_2);
}




void append_data(char* filename_1, char* filename_2) {
	char decision;
	printf("Maybe you want to add anything to your file??? (Y/N)\n");
	scanf_s("%c", &decision);
	if (decision == 'Y') {
		c_functions_caller(filename_1, filename_2);
	}
}
































