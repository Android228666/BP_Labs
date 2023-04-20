#pragma once
#include <iostream>
#include <string>


class Date {
	int date;
	int month;
	int year;

public:
	int getDate();
	int getMonth();
	int getYear();
	void setDate(int);
	void setMonth(int);
	void setYear(int);
};



class Product {
	std::string name;
	std::string indate;
	std::string outdate;

public:
	std::string getName();
	std::string getInDate();
	std::string getOutDate();
	void setName(std::string name1);
	void setInDate(std::string indate1);
	void setOutDate(std::string outdate1);
};


std::string getDay();
int writeToArray(Product*, int);
void outputArray(Product*, int);
void checkArray(Product*, std::string, int);
Date divideString(std::string);
void functions_caller();
