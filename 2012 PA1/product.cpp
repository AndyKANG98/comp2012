//Submit this file
#include "product.h"
//You are NOT allowed to include any additional library

Product::Product(string n, enum ProductType t, float p):
name(n), type(t), price(p), quantity(0){}

string Product::getName() { return name; }

ProductType Product::getType() { return type; }

float Product::getPrice() { return price; }

int Product::getQuantity() { return quantity; }

bool Product::setPrice(float p){
	if (p > 0) { price = p; return true; }
	return false;
}

bool Product::setQuantity(int q){
	if (q >= 0) { quantity = q; return true; }
	return false;
}

int Product::compare(Product* other){
	if ( fabs(this->getPrice() - other->getPrice()) >= 0.01f ) {
		if (this->getPrice() > other->getPrice())
			return 1;
		else
			return -1;
	}
	else if (this->getName() > other->getName())
		return 1;
	else if (this->getName() < other->getName())
		return -1;
	else
		return 0;
}
