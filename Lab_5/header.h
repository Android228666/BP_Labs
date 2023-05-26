#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>

struct Point;
class TQuadrangle;
double calculateDistance(Point a, Point b);
int getNumber();
TQuadrangle** creatingFunction(int n);
void printResult(TQuadrangle** arr, int n);
void cleanMemory(TQuadrangle** arr, int n);

struct Point {
	double x;
	double y;
};


class TQuadrangle {
	Point mas[4];
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void printType() = 0;
	virtual ~TQuadrangle() {}
	Point getPoint(int i) {
		return mas[i];
	}
	void printInfo() {
		for (int i = 0; i < 4; i++) {
			std::cout << "x" << i + 1 << " = " << getPoint(i).x;
			std::cout << " y" << i + 1 << " = " << getPoint(i).y << std::endl;
		}
		std::cout << "S = " << area() << std::endl;
		std::cout << "P = " << perimeter() << std::endl;
	}

	Point& operator[](int i);
};


class Rectangle : public TQuadrangle {
public:
	double area();
	double perimeter();
	void printType();
};

class Square : public Rectangle {
public:
	double area();
	double perimeter();
	void printType();
};

class Parallelogram : public TQuadrangle {
public:
	double area();
	double perimeter();
	void printType();
};
