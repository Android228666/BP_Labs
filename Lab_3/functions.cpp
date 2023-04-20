#include "header.h"

// Product functions

std::string Product::getName() {
	return name;
}

std::string Product::getInDate() {
	return indate;
}

std::string Product::getOutDate() {
	return outdate;
}

void Product::setName(std::string name1) {
	name = name1;
}

void Product::setInDate(std::string indate1) {
	indate = indate1;
}

void Product::setOutDate(std::string outdate1) {
	outdate = outdate1;
}


// Date functions


int Date::getDate() {
	return date;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}


void Date::setDate(int date1){
	date = date1;
}

void Date::setMonth(int month1) {
	month = month1;
}

void Date::setYear(int year1) {
	year = year1;
}


// Just functions


Date divideString(std::string line) {
	std::string temp;
	Date A;
	temp = line.substr(0, 2);
	A.setDate(stoi(temp));
	temp = line.substr(3, 2);
	A.setMonth(stoi(temp));
	temp = line.substr(6, 4);
	A.setYear(stoi(temp));
	return A;
}


bool checkDate(std::string line) {
	int date, month, year;
	std::string temp;
	Date A = divideString(line);
	date = A.getDate();
	month = A.getMonth();
	year = A.getYear();

	bool i = (year >= 1900 && year <= 2199 && month > 0 && month < 13 && date > 0) && ((month % 2 != 0 && date <= 31 && month <= 7) || (month % 2 == 0 && month != 2 && date <= 30 && month <= 7) ||
		(month > 7 && month % 2 == 0 && date <= 31) || (month > 7 && month % 2 != 0 && date <= 30) ||
		(month == 2 && ((year % 100 != 0 && year % 4 == 0 || year % 100 == 0 && year % 400 == 0)) && date <= 29) ||
		(month == 2 && !(year % 100 != 0 && year % 4 == 0 || year % 100 == 0 && year % 400 == 0) && month <= 2) && date <= 28);

	if (i) {
		return true;
	}
	else {
		return false;
	}
}



std::string getDay() {
	bool checkDate(std::string);
	int check = 0;
	std::string line, temp;

	do {
		std::cout << "Please, write current day, month and year (in format dd-mm-yyyy): ";
		std::getline(std::cin, line);
		if (checkDate(line)) {
			check = 1;
		}
		else {
			check = 0;
			std::cout << "You have wrote day uncorrectly!" << std::endl;
		}
	} while (check != 1);

	return line;
}






int writeToArray(Product* A, int counter) {
	bool checkDate(std::string);
	std::string temp;
	char check = 'N';
	std::cout << "Remember, if you write month or day incorrectly your product won't be in summary array. Below you can check rules and good example of date:" << std::endl;
	std::cout << "0 < date <= 29/30/31(depends on which month), 0 < month <= 12, 1900 <= year <= 2199" << std::endl;
	std::cout << "Good example: 29-03-1989 (date-month-year)" << std::endl;
	std::cout << std::endl;
	do {
		Product p;
		std::cout << "Please, write name of product: ";
		std::cin >> temp;
		p.setName(temp);
		std::cout << "Please, write date of manufacture: ";
		std::cin >> temp;
		p.setInDate(temp);
		std::cout << "Please, write expiration date: ";
		std::cin >> temp;
		p.setOutDate(temp);

		if (checkDate(p.getInDate()) && checkDate(p.getOutDate())) {
			A[counter] = p;
			counter++;
		}
		std::cout << "Would you like to add one more product?(Y/N): ";
		std::cin >> check;
		std::cout << std::endl;
	} while (check == 'Y' || check == 'y');
	
	return counter;
}




void outputArray(Product* A, int counter) {
	for (int i = 0; i < counter; i++) {
		std::cout << "Name: " << A[i].getName() << std::endl;
		std::cout << "Date of manufacture: " << A[i].getInDate() << std::endl;
		std::cout << "Expiration Date: " << A[i].getOutDate() << std::endl;
		std::cout << std::endl;
	}
}


void checkArray(Product* A, std::string line, int counter) {
	bool productSuitability(std::string, std::string);
	std::cout << "\n";
	for (int i = 0; i < counter; i++) {
		if (!productSuitability(A[i].getOutDate(), line)) {
			std::cout << "Product no longer valid: " << A[i].getName() << std::endl;
		}

	}
}




// a - last day ||| b - nowaday
bool productSuitability(std::string a, std::string b) {
	Date LastDay = divideString(a);
	Date Nowaday = divideString(b);

	if (LastDay.getYear() < Nowaday.getYear()) {
		return false;
	}else if(LastDay.getYear() == Nowaday.getYear()){

		if (LastDay.getMonth() < Nowaday.getMonth()) {
			return false;
		}
		else if (LastDay.getMonth() == Nowaday.getMonth()) {

			if (LastDay.getDate() < Nowaday.getDate()) {
				return false;
			}else {
				return true;
			}
		}
		else {
			return true;
		}

	}else {
		return true;
	}
}




void functions_caller() {
	Product products[100];
	int counter = 0;
	std::string check = "N";
	std::string day = getDay();
	do {
		counter = writeToArray(products, counter);
		std::cout << "Array of products: " << std::endl;
		outputArray(products, counter);
		checkArray(products, day, counter);
		std::cout << "Maybe, you want to add other product(Y/N): ";
		std::cin >> check;
	} while(check == "Y" || check == "y");
}
