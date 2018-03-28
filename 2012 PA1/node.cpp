//Submit this file
#include "node.h"
//You are NOT allowed to include any additional library

Node::Node(Shop* s, Node* n): shop(s), next(n) {}

Node::~Node(){
	delete shop;
	shop = nullptr;
	next = nullptr;
}

Shop* Node::getShop() { return shop; }

Node* Node::getNext() { return next; }

void Node::setShop(Shop* s) { shop = s; }

void Node::setNext(Node* n) { next = n; }

