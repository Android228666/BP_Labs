#include "header.h"

// <---------------------------- Classes methods ---------------------------->

Point& TQuadrangle::operator[](int i) {
	return mas[i];
}

double Rectangle::area() {
	double x = (calculateDistance(getPoint(0), getPoint(1)) * calculateDistance(getPoint(1), getPoint(2)));
	return x;
}

double Rectangle::perimeter() {
	return (2 * (calculateDistance(getPoint(0), getPoint(1)) + calculateDistance(getPoint(1), getPoint(2))));
}

void Rectangle::printType() {
	std::cout << "<---------- Rectangle creating ---------->" << std::endl;
}

double Square::area() {
	double x = pow((calculateDistance(getPoint(0), getPoint(1))), 2);
	return x;
}

double Square::perimeter() {
	return (4 * calculateDistance(getPoint(0), getPoint(1)));
}

void Square::printType() {
	std::cout << "<---------- Square creating ---------->" << std::endl;
}

double Parallelogram::area() {
	return ((getPoint(1).y - getPoint(0).y) * calculateDistance(getPoint(1), getPoint(2)));
}

double Parallelogram::perimeter() {
	double x = (2 * (calculateDistance(getPoint(0), getPoint(1)) + calculateDistance(getPoint(1), getPoint(2))));
	return x;
}

void Parallelogram::printType() {
	std::cout << "<---------- Parallelogram creating ---------->" << std::endl;
}

// <---------------------------- Just functions ---------------------------->
double calculateDistance(Point a, Point b) {
	return std::sqrt(std::pow((b.x - a.x), 2) + std::pow((b.y - a.y), 2));
}

double randomizer() {
	double f = (double)rand() / RAND_MAX;
	return f * 10;
}

int* randomArray(int n) {
	int* arr = new int[n];
	int a, b, c;
	srand((unsigned)time(NULL));
	do {
		a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = 1 + rand() % 3;

			if (arr[i] == 1) {
				a = 1;
			}
			else if (arr[i] == 2) {
				b = 1;
			}
			else if (arr[i] == 3) {
				c = 1;
			}
		}
	} while (a + b + c != 3);
	return arr;
}

int getNumber() {
	int n, check = 0;
	do {
		check = 0;
		std::cout << "Please, write number of quadrangles that you want to create: ";
		std::cin >> n;
		if (n < 3) {
			std::cout << "N must be more than 3 or equal to 3!" << std::endl;
			check = 1;
		}
	} while (check);

	return n;
}

TQuadrangle** creatingFunction(int n) {
	int* randomArray(int n);
	double randomizer();
	int triangleType;
	double x, y, t, r, diff;
	
	TQuadrangle** array = new TQuadrangle*[n];
	int* arr = new int[n];
	arr = randomArray(n);
	for (int i = 0; i < n; i++) {
		triangleType = arr[i];
		x = randomizer();
		y = randomizer();
		t = randomizer();
		r = randomizer();

		if (triangleType == 1) {
			Rectangle* R = new Rectangle;
			(*R)[0].x = x;
			(*R)[0].y = y;
			(*R)[1].x = x;
			(*R)[1].y = y + t;
			(*R)[2].x = x + r;
			(*R)[2].y = y + t;
			(*R)[3].x = x + r;
			(*R)[3].y = y;
			array[i] = R;
		}
		else if (triangleType == 2) {
			Square* S = new Square;
			(*S)[0].x = x;
			(*S)[0].y = y;
			(*S)[1].x = x;
			(*S)[1].y = y + t;
			(*S)[2].x = x + r;
			(*S)[2].y = y + t;
			(*S)[3].x = x + r;
			(*S)[3].y = y;
			array[i] = S;
		}
		else {
			Parallelogram* P = new Parallelogram;
			diff = randomizer();
			(*P)[0].x = x;
			(*P)[0].y = y;
			(*P)[1].x = x + diff;
			(*P)[1].y = y + t;
			(*P)[2].x = x + diff + r;
			(*P)[2].y = y + t;
			(*P)[3].x = x + r;
			(*P)[3].y = y;
			array[i] = P;
		}
	}

	return array;
}

void printResult(TQuadrangle** arr, int n) {
	double S = 0, P = 0;
	for (int i = 0; i < n; i++) {
		Parallelogram* parallelogram = dynamic_cast<Parallelogram*>(arr[i]);
		if (parallelogram == nullptr) {
			S += arr[i]->area();
		}
		else {
			P += arr[i]->perimeter();
		}
		arr[i]->printType();
		arr[i]->printInfo();
	}

	std::cout << "\nSum of areas of rectangles and squares = " << S << std::endl;
	std::cout << "Sum of perimeters of parallelograms = " << P << std::endl;

	
}

void cleanMemory(TQuadrangle** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete[] arr;
}
