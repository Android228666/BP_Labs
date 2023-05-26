#include "header.h"

int main() {
	int n = getNumber();
	TQuadrangle** arr = creatingFunction(n);
	printResult(arr, n);
	cleanMemory(arr, n);
	return 0;
}
