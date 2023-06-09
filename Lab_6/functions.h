#pragma once
#include "HashSet.h"
template<typename T, int setN>
HashSet<T> enterSet() {
	int capacity, size;
	T element;

	std::cout << "What is the capacity of the set" << setN << ": ";
	std::cin >> capacity;
	HashSet<T> set(capacity);
	

	std::cout << "How many elements would you like to add to the set" << setN << ": ";
	std::cin >> size;

	for (int i = 0; i < size; i++) {
		std::cout << "Enter an element that you would like to add: ";
		std::cin >> element;
		set.add(element);
	}

	return set;
}

template <typename T>
void addElement(HashSet<T>& set) {
	T element;
	std::cout << "Enter an element: ";
	std::cin >> element;
	set.add(element);
}

template <typename T>
void checkContains(HashSet<T>& set) {
	T element;
	std::cout << "Enter an element: ";
	std::cin >> element;
	if (set.contains(element)) {
		std::cout << "Element is in the set." << std::endl;
	}
	else {
		std::cout << "The element with that value wasn't found.\n";
	}
}

template <typename T>
void clearSet(HashSet<T>& set) {
	set.clear();
	std::cout << "Set was clear successfully!\n";
}

template <typename T>
void calculateDifference(HashSet<T>& set1, HashSet<T>& set2) {
	HashSet<T> set3 = set2 - set1;
	HashSet<T> set4 = set1 - set2;
	std::cout << "set2 \\ set1: ";
	set3.printSet();
	std::cout << "set1 \\ set2: ";
	set4.printSet();
}

template<typename T>
void startFunction() {
	int check = 1, number;
	HashSet<T> set1 = enterSet<T, 1>();
	HashSet<T> set2 = enterSet<T, 2>();
	do {
		std::cout << "\n<--------------------- MENU --------------------->" << std::endl;
		std::cout << "Enter 1 if you want to add an element to the set1." << std::endl;
		std::cout << "Enter 2 if you want to add an element to the set2." << std::endl;
		std::cout << "Enter 3 if you want to check if set1 contains an element." << std::endl;
		std::cout << "Enter 4 if you want to check if set2 contains an element." << std::endl;
		std::cout << "Enter 5 if you want to clear the set1." << std::endl;
		std::cout << "Enter 6 if you want to clear the set2." << std::endl;
		std::cout << "Enter 7 if you want to calculate difference between sets." << std::endl;
		std::cout << "Enter 8 if you want to print set1." << std::endl;
		std::cout << "Enter 9 if you want to print set2." << std::endl;
		std::cout << "Enter 10 if you want to end. " << std::endl;
		std::cout << "Number: ";
		std::cin >> number;

		switch (number) {
			case 1:
				addElement(set1);
				break;
			case 2:
				addElement(set2);
				break;
			case 3:
				checkContains(set1);
				break;
			case 4:
				checkContains(set2);
				break;
			case 5:
				clearSet(set1);
				break;
			case 6:
				clearSet(set2);
				break;
			case 7:
				calculateDifference(set1, set2);
				break;
			case 8:
				set1.printSet();
				break;
			case 9:
				set2.printSet();
				break;
			case 10:
				check = 0;
				break;
		}

	} while (check);
}





