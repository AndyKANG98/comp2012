//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must NOT be implemented here


Mall::Mall(string n, string a): name(n), address(a), shopHead(nullptr){}

Mall::Mall(Mall& another):name(another.getName()), address(another.getAddress()),
		shopHead(duplicateShopLinkedList(another.shopHead)){}

Mall::~Mall(){
	Node* temp_node = shopHead;
	if (temp_node != nullptr){
		Node* next_node = temp_node->getNext();

		while (next_node != nullptr){
			delete temp_node;
			temp_node = next_node;
			next_node = next_node->getNext();
		}
		delete temp_node;
		temp_node = nullptr;
	}

}

void Mall::setName(string n){ name = n; }

void Mall::setAddress(string ad){ address = ad; }

string Mall::getName(){ return name; }

string Mall::getAddress(){ return address; }

bool Mall::addShop(string n, int shopNum){
	Node* head = shopHead;

	if (head == nullptr){
		Shop* newShop = new Shop(n, shopNum);
		Node* newNode = new Node(newShop, nullptr);
		shopHead = newNode;
		return true;
	}

	while (head->getNext() != nullptr){
		if (head->getShop()->getShopNumber() == shopNum)
			return false;
		head = head->getNext();
	}
	if (head->getShop()->getShopNumber() == shopNum)
		return false;

	Shop* newShop = new Shop(n, shopNum);
	Node* newNode = new Node(newShop, nullptr);
	head->setNext(newNode);
	return true;
}

bool Mall::removeShop(int shopNum){
	Node* head = shopHead;
	if (head == nullptr)
		return false;

	if (head->getShop()->getShopNumber() == shopNum){
		shopHead = head->getNext();
		delete head;
		head = nullptr;
		return true;
	}

	do{
		if (head->getNext()->getShop()->getShopNumber() == shopNum){
			Node* temp = head->getNext();
			head->setNext(temp->getNext());
			delete temp;
			temp = nullptr;

			return true;
		}
		head = head->getNext();
	}while (head->getNext() != nullptr);

	return false;
}

Shop* Mall::getShop(int shopNum){
	Node* head = shopHead;
	if (head == nullptr)
		return nullptr;

	do{
		if (head->getShop()->getShopNumber() == shopNum)
			return head->getShop();
	}while (head->getNext() != nullptr);

	return nullptr;
}

