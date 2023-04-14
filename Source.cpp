#include <iostream>
#include <iomanip>
#include "Products.h"

int main() {
	product prod1{ "Laptop", 10, 49999.00 };
	product prod2{ "TV", 15, 39999.99 };
	product prod3{ "Smartphone", 20, 29999.99 };
	const int qty = 3;
	product goods[qty]{ prod1, prod2, prod3 };
	
	std::cout << "\tStock analysis :\n";
	for (int i = 0; i < qty; i++) {
		print_prod(goods[i]);
		std::cout << "Total cost of all " << goods[i].name << "s in stock: " 
			<< std::fixed << std::setprecision(2) << full_price(goods[i]) << " RUB.\n\n";
	}
	
	int product_choice, amount, counter = 0;
	double sum = 0.0;
	char answer = 'y';
	while (std::tolower(answer) == 'y') {	// Cycle for multiple shipment
		std::cout << "Choose a product to sell ->\n";
		for (int i = 0; i < qty; i++)
			std::cout << i + 1 << " - " << goods[i].name << '\n';
		std::cout << "(or press 0 to exit) -> ";
		do {	// Cycle for correct product choice with non-zero stock residuals check
			std::cin >> product_choice;
			if (product_choice == 0)
				break;
			else 
				if (product_choice >= 1 && product_choice <= qty && goods[product_choice - 1].number > 0)
					break;
				else 
					if (product_choice >= 1 && product_choice <= qty && goods[product_choice - 1].number == 0) {
						std::cout << "No left in stock!\nChoose another product -> ";
						continue;
					}
					else
						std::cout << "No such product found!\nRepeate you choice -> ";
						continue;
			
		} while (true);
		if (product_choice == 0)
			break;
		for (int i = 0; i < qty; i++)
			if (product_choice == i + 1) {
				std::cout << std::endl;
				std::cout << "Chosen product:\n";
				print_prod(goods[i]);
				std::cout << "Enter amount -> ";
				do {	// Cycle for correct amount choice
					std::cin >> amount;
					if (amount >= 0 && amount <= goods[i].number)
						break;
					else {
						std::cout << "Incorrect amount! Left in stock: " << goods[i].number << "\nRepeate enter amount-> ";
						continue;
					}
				} while (true);
				std::cout << "Sale price = " << std::fixed << std::setprecision(2) << sell_price(goods[i], amount) << " RUB\n";
				sell(goods[i], amount);
				std::cout << "Left in stock: " << goods[i].number << '\n';
				if (goods[i].number == 0)	// If the product is sold out
					counter++;
				sum += sell_price(goods[i], amount);
				std::cout << "Total invoice sum = " << std::fixed << std::setprecision(2) << sum << " RUB.\n\n";
				break;
			}
		if (counter == qty) {	// If there are no any products left in stock 
			std::cout << "Stock is empty!\n";
			break;
		}
		else {
			std::cout << "Do you want to add products to the shipping (Y/N)? ";
			std::cin >> answer;
		}
	}
	std::cout << "\nEnd of programm.\n";

	return 0;
}