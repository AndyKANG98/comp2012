//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library

Shop::Shop(string n, int shopNum):
name(n), shopNumber(shopNum), productCount(0), products(nullptr){}

Shop::Shop(Shop& another):
		name(another.name), shopNumber(another.shopNumber),
		productCount(another.productCount), products(new Product* [another.productCount]){
	for (int i=0; i<productCount; i++){
		Product* s = new Product(another.products[i]->getName(),
				another.products[i]->getType(), another.products[i]->getPrice());
		s->setQuantity(another.products[i]->getQuantity());
		products[i] = s;
	}
}


Shop::~Shop(){
	for (int i=0; i<productCount; i++){
		delete products[i];
		products[i] = nullptr;
	}
	delete []products;
	products = nullptr;
}

string Shop::getName() { return name; }

int Shop::getShopNumber() { return shopNumber; }

void Shop::setName(string n) { name = n; }

void Shop::setShopNumber(int shopNum) { shopNumber = shopNum; }

void Shop::addProduct(string n, ProductType t, float p, int q){

	for (int i=0; i<productCount; i++){
		if (products[i]->getName() == n){
			products[i]->setQuantity(products[i]->getQuantity() + q);
			return;
		}
	}


	if (products == nullptr){

		Product* productToAdd = new Product(n, t, p);
		productToAdd->setQuantity(q);
		Product** NewProducts = new Product* [productCount + 1];

		NewProducts[0] = productToAdd;

		products = NewProducts;
		productCount++;

		NewProducts = nullptr;
		productToAdd = nullptr;
		return;
	}

	else{
		Product* productToAdd = new Product(n, t, p);
		productToAdd->setQuantity(q);
		Product** NewProducts = new Product* [productCount + 1];
		int new_position = 0;

		for (int i=0; i<productCount; i++){
			if (productToAdd->compare(products[i]) == 1){
				Product* product_i = new Product(products[i]->getName(), products[i]->getType(), products[i]->getPrice());
				product_i->setQuantity(products[i]->getQuantity());
				NewProducts[i] = product_i;
				new_position ++;
				continue;
			}

			if (productToAdd->compare(products[i]) == -1){
				break;
			}
		}

		NewProducts[new_position] = productToAdd;


		for (int j = new_position; j<productCount; j++){
			Product* product_j = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
			product_j->setQuantity(products[j]->getQuantity());
			NewProducts[j+1] = product_j;
		}

//Delete the original one
		for (int i=0; i<productCount; i++){
			delete products[i];
			products[i] = nullptr;
		}
		delete []products;
		products = NewProducts;
		productToAdd = nullptr;
		NewProducts = nullptr;
		productCount++;
		return;

	}

}

bool Shop::removeProduct(string n, int qToRemove){
	if (qToRemove <= 0)
		return false;

	int contain = 0;
	for (int i=0; i<productCount; i++){
		if (products[i]->getName() == n){
			contain++;
			if (products[i]->getQuantity() < qToRemove)
				return false;
			products[i]->setQuantity(int (products[i]->getQuantity() - qToRemove));
			if (products[i]->getQuantity() == 0){
				Product** NewProducts = new Product* [productCount - 1];
				for (int j=0; j<productCount; j++){
					if (j < i){
						Product* product_j = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
						product_j->setQuantity(products[j]->getQuantity());
						NewProducts[j] = product_j;
					}

					else if (j > i){
						Product* product_j = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
						product_j->setQuantity(products[j]->getQuantity());
						NewProducts[j-1] = product_j;
					}

				}
				//Delete the original one
				for (int i=0; i<productCount; i++){
					delete products[i];
					products[i] = nullptr;
				}
				delete []products;
				products = NewProducts;
				NewProducts = nullptr;
				productCount--;
				break;
			}
		}
	}
	if (contain == 0)
		return false;

	return true;
}

Product* Shop::findProduct(string n){
	for (int i=0; i<productCount; i++){
		if (products[i]->getName() == n)
			return products[i];
	}
	return nullptr;
}

bool Shop::updatePrice(string n, float p){
	if (p <= 0)
		return false;

	int contain = 0;
	for (int i=0; i<productCount; i++){
		if (products[i]->getName()  == n){
			string temp_name = products[i]->getName();
			ProductType temp_type = products[i]->getType();

			int temp_quantity = products[i]->getQuantity();

			this->removeProduct(temp_name, temp_quantity);
			this->addProduct(temp_name, temp_type, p, temp_quantity);

			contain++;
			break;
		}
	}
	if (contain == 0)
		return false;

	return true;
}

