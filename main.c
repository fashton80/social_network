///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "functions"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum Constants {
	name_length = 25,
	tree_list = 1,
	user_list = 2,
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* address;
	char* firstName;
	char* lastName;
}TreeNode;

struct TreeNode* listTreeRoot = NULL;  //listTreeRoots tree is forcing the tree of the rootNode to mimick its tree

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* address;
}Node;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	printf("size of node is %d and treenode is %d\n", sizeof(Node), sizeof(TreeNode));

	struct TreeNode* mike = CreateNode(tree_list);
	(*mike).lastName = InsertName((*mike).lastName);
	listTreeRoot = InsertNode(listTreeRoot, mike, tree_list);

	struct TreeNode* collin = CreateNode(tree_list);
	(*collin).lastName = InsertName((*collin).lastName);
	listTreeRoot = InsertNode(listTreeRoot, collin, tree_list);

	struct TreeNode* taylor = CreateNode(tree_list);
	(*taylor).lastName = InsertName((*taylor).lastName);
	listTreeRoot = InsertNode(listTreeRoot, taylor, tree_list);

	struct TreeNode* zeke = CreateNode(tree_list);
	(*zeke).lastName = InsertName((*zeke).lastName);
	listTreeRoot = InsertNode(listTreeRoot, zeke, tree_list);

	struct TreeNode* nancy = CreateNode(tree_list);
	(*nancy).lastName = InsertName((*nancy).lastName);
	listTreeRoot = InsertNode(listTreeRoot, nancy, tree_list);

	struct TreeNode* patterson = CreateNode(tree_list);
	(*patterson).lastName = InsertName((*patterson).lastName);
	listTreeRoot = InsertNode(listTreeRoot, patterson, tree_list);

	struct TreeNode* ollie = CreateNode(tree_list);
	(*ollie).lastName = InsertName((*ollie).lastName);
	listTreeRoot = InsertNode(listTreeRoot, ollie, tree_list);

	struct TreeNode* ashton = CreateNode(tree_list);
	(*ashton).lastName = InsertName((*ashton).lastName);
	listTreeRoot = InsertNode(listTreeRoot, ashton, tree_list);

	struct TreeNode* destiny = CreateNode(tree_list);
	(*destiny).lastName = InsertName((*destiny).lastName);
	listTreeRoot = InsertNode(listTreeRoot, destiny, tree_list);

	size_t height = FindHeight(listTreeRoot);
	printf("height is %u\n", height);

	PrintTreeInOrder(listTreeRoot, tree_list);
	printf("\n");
	//PrintTreePreOrder(listTreeRoot, tree_list1);
	//printf("\n");
	//PrintTreePostOrder(listTreeRoot, tree_list);
	//printf("\n");
	//PrintTreeInOrderReverse(listTreeRoot, tree_list);
	printf("\n");
	////

	(*mike).address = CreateNode(user_list);
	(*((*mike).address)).address = mike;
	(*mike).address = InsertNode((*mike).address, collin, user_list);
	(*mike).address = InsertNode((*mike).address, taylor, user_list);
	(*mike).address = InsertNode((*mike).address, zeke, user_list);
	(*mike).address = InsertNode((*mike).address, nancy, user_list);
	(*mike).address = InsertNode((*mike).address, patterson, user_list);
	(*mike).address = InsertNode((*mike).address, ollie, user_list);

	size_t check = CheckFriends((*mike).address, collin);
	printf("checkfriends is: %u\n\n", check);
	////
	//(*collin).address = CreateNode(user_list);
	//(*((*collin).address)).address = collin;
	//(*collin).address = InsertNode((*collin).address, mike, user_list);
	//(*collin).address = InsertNode((*collin).address, zeke, user_list);
	////
	//printf("\n\nmikes tree below:\n");
	//PrintTreeInOrder((*mike).address, user_list);

	printf("\nDELETED tree edit below:\n\n");

	//DeleteNode((*mike).address, patterson, user_list);			//when deleting user from app, delete in friends groups first then rootlist
	//DeleteNode((*mike).address, taylor, user_list);			//when deleting user from app, delete in friends groups first then rootlist
	//DeleteNode((*mike).address, collin, user_list);			//when deleting user from app, delete in friends groups first then rootlist
	//DeleteNode((*mike).address, nancy, user_list);			//when deleting user from app, delete in friends groups first then rootlist
	//DeleteNode(listTreeRoot, collin, tree_list);
	//DeleteNode(listTreeRoot, nancy, tree_list);
	//DeleteNode(listTreeRoot, taylor, tree_list);


	//DeleteNode(listTreeRoot, mike, tree_list);

	size_t test = CheckTreeBalance(listTreeRoot);
	printf("testname is %u\n", test);
	//printf("\n");
	//PrintTreeInOrder(listTreeRoot, tree_list);

	//printf("\n\nmikes tree below:\n");
	//PrintTreeInOrder((*mike).address, user_list);
	//printf("\n\ncollins tree below:\n");

	//PrintTreeInOrder((*collin).address, user_list);
	//struct Node* parent = FindParentNode();

	DeleteNode(listTreeRoot, taylor, tree_list);
	//printf("\ntreeRoot below:\n\n");
	//PrintTreeInOrder(listTreeRoot, tree_list);

	DeleteNode(listTreeRoot, nancy, tree_list);
	//printf("\ntreeRoot below:\n\n");
	//PrintTreeInOrder(listTreeRoot, tree_list);

	DeleteNode(listTreeRoot, patterson, tree_list);  //error thrown here
	printf("\ntreeRoot below:\n\n");
	PrintTreeInOrder(listTreeRoot, tree_list);

	DeleteNode(listTreeRoot, collin, tree_list);  //error thrown here
	printf("\ntreeRoot below:\n\n");
	PrintTreeInOrder(listTreeRoot, tree_list);

	////////////temp needs to be struct Node not TreeNode in delete
	////////////checktreebalance not working, flow is off

	int c = getchar();
}

//insert node works for both node into treenode (new user in network) and node into node (aka friends)
