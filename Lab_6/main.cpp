#include "HashSet.h"
#include "functions.h"
#define SIZE 50

int main() {

	int check = 0, typeNumber;
	do {
		std::cout << "1 - int;" << std::endl;
		std::cout << "2 - double;" << std::endl;
		std::cout << "3 - float;" << std::endl;
		std::cout << "4 - bool;" << std::endl;
		std::cout << "5 - char;" << std::endl;
		std::cout << "6 - string;" << std::endl;
		std::cout << "Choose type of element in the set: ";
		std::cin >> typeNumber;

		switch (typeNumber) {
		case 1:
			startFunction<int>();
			break;
		case 2:
			startFunction<double>();
			break;
		case 3:
			startFunction<float>();
			break;
		case 4:
			startFunction<bool>();
			break;
		case 5:
			startFunction<char>();
			break;
		case 6:
			startFunction<std::string>();
			break;
		default:
			"Remember! You can write only numbers from 1 to 5.";
		}
	} while (check);
