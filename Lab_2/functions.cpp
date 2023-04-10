#include "header.h"



bool checkDate(std::string line) {
	int date, month, year;
	std::string temp;
	temp = line.substr(0, 2);
	date = stoi(temp);
	temp = line.substr(3, 2);
	month = stoi(temp);
	temp = line.substr(6, 4);
	year = stoi(temp);

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


curDay getDay() {
	int check = 0;
	std::string line, temp;
	curDay A;
	
	do {
		std::cout << "Please, write current day, month and year (in format dd/mm/yyyy): ";
		std::getline(std::cin, line);
		temp = line.substr(0, 2);
		A.date = stoi(temp);
		temp = line.substr(3, 2);
		A.month = stoi(temp);
		temp = line.substr(6, 4);
		A.year = stoi(temp);

		if (checkDate(line)) {
			check = 1;
		}
		else {
			check = 0;
			std::cout << "You have wrote day uncorrectly!" << std::endl;
		}

	} while (check != 1);

	return A;
}



void writeFile(std::string filename) {

	std::ofstream write(filename, std::ios::binary | std::ios::app);
	int n;
	std::string check = "N";
	Customer A;
	
	do {
		std::cout << "Please, enter a number of customers: ";
		std::cin >> n;
		std::cout << "Remember, if you write month or day incorrectly your user won't be in summary list. Below you can check rules and good example of date:" << std::endl;
		std::cout << "0 < date <= 29/30/31(depends on which month), 0 < month <= 12, 1900 <= year <= 2199" << std::endl;
		std::cout << "Good example: 29/03/1989 (date/month/year)" << std::endl;
		
		for (int i = 0; i < n; i++) {
			std::cin.ignore();
			std::cout << "Please, enter a surname of person: ";
			std::cin.getline(A.surname, sizeof(A.surname));

			std::cout << "Please, enter a gender of person: ";
			std::cin.getline(A.gender, sizeof(A.gender));

			std::cout << "Please, enter a date of person birth(example: 22/10/2004): ";
			std::cin.getline(A.birth, sizeof(A.birth));

			std::cout << "Please, enter a number of good: ";
			std::cin >> A.count;

			if (checkDate(A.birth)) {
				write.write((char*)&A, sizeof(Customer));
			}
			std::cout << std::endl;
		}

		std::cout << "Maybe, you want to add other customers(Y/N): ";
		std::cin >> check;
	} while (check == "Y" || check == "y");

	write.close();
}




void readFile(std::string filename) {
	std::ifstream read(filename, std::ios::binary);
	Customer A;


	while(read.read((char*)&A, sizeof(Customer))) {
		std::cout << "Surname: " << A.surname << std::endl;
		std::cout << "Gender: "  << A.gender  << std::endl;
		std::cout << "Birth: "   << A.birth   << std::endl;
		std::cout << "Count: "   << A.count   << std::endl;
		std::cout << std::endl;
	}

	read.close();

}


float discount(std::string filename_1, curDay D) {
	int calculateAge(std::string line, curDay D);
	void fillSecond(Customer);
	std::ifstream read(filename_1, std::ios::binary);
	Customer A;
	std::string temp, line;
	float total = 0;
	
	while (read.read((char*)&A, sizeof(Customer))) {
		int age = calculateAge(A.birth, D);
		float x = A.count;
		if (age >= 60) {
			x = (x - (float)age / 100) * 0.95;
			total += x;
		}
		else {
			x = x - (float)age/100;
			total += x;
		}

		if (x*100 > 250) {
			fillSecond(A);
		}

	}

	total *= 100;
	read.close();

	std::cout << "TOTAL SUM = " << total << std::endl;
	return total;
}




int calculateAge(std::string line, curDay D) {
	std::string temp;
	int birth_date, birth_month, birth_year, age;
	int cur_date = D.date,
		cur_month = D.month,
		cur_year = D.year;

	temp = line.substr(0, 2);
	birth_date = stoi(temp);
	temp = line.substr(3, 2);
	birth_month = stoi(temp);
	temp = line.substr(6, 4);
	birth_year = stoi(temp);
	
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (birth_date > cur_date) {
		cur_date += month[birth_month - 1];
		cur_month--;
	}

	if (birth_month > cur_month) {
		cur_year--;
		cur_month += 12;
	}
	age = cur_year - birth_year;
	return age;
}


void fillSecond(Customer B) {
	std::string filename_1 = "final_file.bin";
	std::ofstream write(filename_1, std::ios::binary | std::ios::app);
	write.write((char*)&B, sizeof(Customer));
	write.close();
}




void functionCaller() {
	std::string check = "N";
	curDay B = getDay();
	do {
		std::string filename_1 = "first_file.bin";
		std::string filename_2 = "final_file.bin";
		writeFile(filename_1);
		std::cout << "Customers_file: " << std::endl;
		readFile(filename_1);
		std::ofstream clean("final_file.bin", std::ios::trunc);
		clean.close();
		discount(filename_1, B);
		std::cout << std::endl << "Final_file: " << std::endl;
		readFile(filename_2);

		std::cout << "Maybe, you want to add other customers(Y/N): ";
		std::cin >> check;
	} while (check == "Y" || check == "y");
}





