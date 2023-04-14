#ifndef _PRODUCTS_H_
#define _PRODUCTS_H_

#include <string>

struct product {
	std::string name;
	int number = 0;
	double price;
};

void print_prod(const product& P);

inline double full_price(const product& P) { 
	return (P.price * double(P.number));
}

inline double sell_price(const product& P, int num) {
	return (P.price * double(num));
}

inline void sell(product& P, int num) {
	P.number -= num;
}

#endif


