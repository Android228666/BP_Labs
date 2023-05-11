#include "header.h"

// <---------------------------- Operators overriding ---------------------------->

Numeral_16 Numeral_16::operator++() {
	int dec = fromHexToDecimal(hex);
	dec++;
	hex = fromDecimalToHex(dec);
	return *this;
}

Numeral_16 Numeral_16::operator+=(int x) {
	int dec = fromHexToDecimal(hex);
	dec += x;
	hex = fromDecimalToHex(dec);
	return *this;
}


Numeral_16 operator+(Numeral_16 x1, Numeral_16 x2) {
	Numeral_16 res;
	res.hex = (fromDecimalToHex(fromHexToDecimal(x1.hex) + fromHexToDecimal(x2.hex)));
	return res;
}


// <---------------------------- Functions ---------------------------->

std::string Numeral_16::convertToBinary() {
	std::string fromDecimalToBinary(int);
	std::string binary = "";
	int length = hex.length();
	int base = 1;
	int decimalForm = 0;
	
	for (int i = length - 1; i >= 0; i--) {

		if (hex[i] >= '0' && hex[i] <= '9') {
			decimalForm += (int(hex[i]) - 48) * base;
			base *= 16;
		}
		else if(hex[i] >= 'A' && hex[i] <= 'F') {
			decimalForm += (int(hex[i]) - 55) * base;
			base *= 16;
		}
	}
	//std::cout << "decimalForm = " << decimalForm << std::endl;
	binary = fromDecimalToBinary(decimalForm);

	return binary;
}

std::string Numeral_16::convertToShortBinary() {
	std::string fromDecimalToBinary(int);
	std::string binary = "", temp = "";
	int length = hex.length();

	for (int i = 0; i < length; i++) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			temp = fromDecimalToBinary(int(hex[i]) - 48);
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			temp = fromDecimalToBinary(int(hex[i]) - 55);
		}

		while (temp.length() <= 3) {
			temp.insert(0, 1, '0');
		}

		binary += temp;

		if (i < length) {
			binary += " ";
		}
		temp = "";
	}
	return binary;
}


std::string fromDecimalToBinary(int decimal) {
	std::string binary = "";
	while (decimal != 0) {
		if (decimal % 2 == 0) {
			binary.insert(0, 1, '0');
		}
		else {
			binary.insert(0, 1, '1');
		}

		decimal /= 2;
		//std::cout << "binary = " << binary << std::endl;
		//std::cout << "decimal_cycleForm = " << decimalForm << std::endl;
	}

	return binary;
}

int fromHexToDecimal(std::string hex) {
	int length = hex.length();
	int base = 1;
	int decimalForm = 0;
	for (int i = length - 1; i >= 0; i--) {

		if (hex[i] >= '0' && hex[i] <= '9') {
			decimalForm += (int(hex[i]) - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			decimalForm += (int(hex[i]) - 55) * base;
			base *= 16;
		}
		//else {
			//std::cout << "Sorry, but some symbol: " << hex[i] << " can't be in hexadecimal number." << std::endl;
			//break;
		//}
	}

	return decimalForm;
}

std::string fromDecimalToHex(int decimal) {
	std::string hex = "";

	while (decimal != 0) {
		int remainder;
		char ch = ' ';

		remainder = decimal % 16;

		if (remainder < 10) {
			ch = remainder + 48;
		}
		else if (remainder >= 10 && remainder < 16) {
			ch = remainder + 55;
		}
		hex.insert(0, 1, ch);
		decimal /= 16;
	}

	return hex;
}
