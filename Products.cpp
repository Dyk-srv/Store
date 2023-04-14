#include "Products.h"
#include <iostream>
#include <iomanip>

void print_prod(const product& P) {
	std::cout << "Name:           " << P.name << '\n';
	std::cout << "Qty in stock:   " << P.number << '\n';
	std::cout << "Price per unit: " << std::fixed << std::setprecision(2) << P.price << " RUB\n";
}
