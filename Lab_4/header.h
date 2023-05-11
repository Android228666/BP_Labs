#pragma once
#include <iostream>
#include <string>


int fromHexToDecimal(std::string);
std::string fromDecimalToHex(int);

class Numeral_16 {
	std::string hex;
public:
	Numeral_16() {
		hex = "";
	}

	Numeral_16(std::string hex1) {
		hex = hex1;
	}

	Numeral_16(const Numeral_16& obj) {
		hex = obj.hex;
	}

	std::string getNum() {
		return hex;
	}

	std::string convertToBinary();
	std::string convertToShortBinary();
	Numeral_16 operator++();
	Numeral_16 operator+=(int x);
	friend Numeral_16 operator+(Numeral_16, Numeral_16);
};
