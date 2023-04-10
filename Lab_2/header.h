#include <iostream>
#include <fstream>
#include <string>



struct curDay {
	int date;
	int month;
	int year;
};


struct Customer {
	char surname[30];
	char gender[10];
	char birth[12];
	int count;
};

void writeFile(std::string);
void readFile(std::string);
curDay getDay();
float discount(std::string, curDay);
void functionCaller();
