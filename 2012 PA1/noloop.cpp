//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must be implemented here
//NOTE: recursion is a requirement - NO loops of any kind is allowed in this file
//a checking needs to be done by you after you finish your code, please refer to the 4th item in "Additional notes" on the webpage

Node* Mall::duplicateShopLinkedList(Node* node){
	if (node == nullptr)
		return nullptr;

	Shop* new_shop = new Shop(*node->getShop());
	Node* new_node = new Node(new_shop, duplicateShopLinkedList(node->getNext()));
	return new_node;
}


/* Failed test case 11 [Expected output:
Test case 11: Mall: HKUST Mall @ Clear Water Bay
Shops in HKUST Mall: nullptr Mall: HKUST Super Mall @ Clearer Water Bay
Add result: true
Shops in HKUST Super Mall: (1,"Supermarket") -> nullptr
Add result: false
Shops in HKUST Super Mall: (1,"Supermarket") -> nullptr
Add result: true
Shops in HKUST Super Mall: (1,"Supermarket") -> (2,"Supermarket 2") -> nullptr
Add result: false
Shops in HKUST Super Mall: (1,"Supermarket") -> (2,"Supermarket 2") -> nullptr
printShop: No such shop.
Shop: #1 Supermarket
Shop: #2 Supermarket 2
printShop: No such shop."

Your output on our machine:
Test case 11: Mall: HKUST Mall @ Clear Water Bay
Shops in HKUST Mall: nullptr Mall: HKUST Super Mall @ Clearer Water Bay
Add result: true
Shops in HKUST Super Mall: (1,"Supermarket") -> nullptr
Add result: false
Shops in HKUST Super Mall: (1,"Supermarket") -> nullptr
Add result: true
Shops in HKUST Super Mall: (1,"Supermarket") -> (2,"Supermarket 2") -> nullptr
Add result: false
Shops in HKUST Super Mall: (1,"Supermarket") -> (2,"Supermarket 2") -> nullptr"];
*/
