#include "header.h"

int main() {
	Numeral_16 N1("A15");
	Numeral_16 N2("13C");
	Numeral_16 N3;
	std::cout << "N1 = " << N1.getNum() << std::endl;
	std::cout << "N2 = " << N2.getNum() << std::endl;
	++N1;
	std::cout << "\nIncremented N1 = " << N1.getNum() << std::endl;
	N2 += 255;
	std::cout << "Invremented N2 by 255 = " << N2.getNum() << std::endl;
	N3 = N1 + N2; 
	std::cout << "\nSum of N1 and N2:\n";
	std::cout << "Result number: " << N3.getNum() << std::endl;
	std::cout << "Binary form: " << N3.convertToBinary() << std::endl;
	std::cout << "Short binary form: " << N3.convertToShortBinary() << std::endl;
	return 0;
}
