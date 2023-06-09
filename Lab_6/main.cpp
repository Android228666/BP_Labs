#include "HashSet.h"
#define SIZE 50

int main() {
	std::cout << "<---------------------- For INT ---------------------->" << std::endl;
	HashSet<int> set1(SIZE);
	set1.add(5);
	set1.add(10);
	set1.add(50);
	set1.add(11);
	set1.add(10); // ---
	std::cout << "Size1 = " << set1.size() << std::endl;
	std::cout << "Consist 5? - " << set1.contains(5) << std::endl;
	std::cout << "Consist 25? - " << set1.contains(25) << std::endl;

	HashSet<int>::Iterator it1(set1, 14);
	it1 = set1.begin();
	std::cout << "Iterator point to: " << it1.getCurrentItem() << std::endl;
	it1++;
	std::cout << "Iterator Iterator point to (after ++): " << it1.getCurrentItem() << std::endl;
	std::cout << "Set1: ";
	set1.printSet();

	HashSet<int> set2(SIZE);
	set2.add(500);
	set2.add(10);
	set2.add(11);
	std::cout << "Set2: ";
	set2.printSet();

	HashSet<int> set3(SIZE);
	set3 = set2 - set1;
	std::cout << "Set3(Set2 \\ Set1): ";
	set3.printSet();
	set3 = set1 - set2;
	std::cout << "Set3(Set1 \\ Set2): ";
	set3.printSet();

	std::cout << "Size3 before clear = " << set3.size() << std::endl;
	set3.clear();
	std::cout << "Size3 after clear = " << set3.size() << std::endl;

	std::cout << "<---------------------- For CHAR ---------------------->" << std::endl;
	HashSet<char> set4(SIZE);
	set4.add('a');
	set4.add('v');
	set4.add('c');
	set4.add('b');
	set4.add('a');
	std::cout << "Size1 = " << set4.size() << std::endl;
	std::cout << "Contains x? - " << set4.contains('x') << std::endl;
	std::cout << "Contains a? - " << set4.contains('a') << std::endl;

	HashSet<char>::Iterator it2(set4, 0);
	it2 = set4.begin();
	std::cout << "Iterator point to: " << it2.getCurrentItem() << std::endl;
	it2++;
	std::cout << "Iterator Iterator point to (after ++): " << it2.getCurrentItem() << std::endl;
	std::cout << "Set1: ";
	set1.printSet();

	HashSet<char> set5(SIZE);
	set5.add('5');
	set5.add('r');
	set5.add('a');
	std::cout << "Set2: ";
	set5.printSet();

	HashSet<char> set6(SIZE);
	set6 = set5 - set4;
	std::cout << "Set3(Set2 \\ Set1): ";
	set3.printSet();
	set6 = set4 - set5;
	std::cout << "Set3(Set1 \\ Set2): ";
	set3.printSet();

	std::cout << "Size3 before clear = " << set6.size() << std::endl;
	set6.clear();
	std::cout << "Size3 after clear = " << set6.size() << std::endl;

	std::cout << "<---------------------- For STRING ---------------------->" << std::endl;
	HashSet<std::string> set7(SIZE);
	set7.add("John");
	set7.add("500");
	set7.add("!");
	set7.add("What?");
	set7.add("Time");
	std::cout << "Size1 = " << set7.size() << std::endl;
	std::cout << "Contains John? - " << set7.contains("John") << std::endl;
	std::cout << "Contains Anna? - " << set7.contains("Anna") << std::endl;
	HashSet<std::string>::Iterator it3(set7, 0);
	it3 = set7.begin();
	std::cout << "Iterator point to: " << it3.getCurrentItem() << std::endl;
	it3++;
	std::cout << "Iterator Iterator point to (after ++): " << it3.getCurrentItem() << std::endl;
	std::cout << "Set1: ";
	set1.printSet();

	HashSet<std::string> set8(SIZE);
	set8.add("Hi");
	set8.add("Hello");
	set8.add("25");
	set8.add("!");
	set8.add("!");
	std::cout << "Set2: ";
	set8.printSet();
	

	HashSet<std::string> set9(SIZE);
	set9 = set8 - set7;
	std::cout << "Set3(Set2 \\ Set1): ";
	set9.printSet();
	set9 = set7 - set8;
	std::cout << "Set3(Set1 \\ Set2): ";
	set9.printSet();
	std::cout << "Size3 before clear = " << set9.size() << std::endl;
	set9.clear();
	std::cout << "Size3 after clear = " << set9.size() << std::endl;



	return 0;
}
