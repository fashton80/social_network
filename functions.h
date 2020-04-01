#include "functions.c"

void* malloc(size_t size);    //allocates memory on the heap in bytes
void free(void* ptr);    //frees memory allocated to by ptr
void sfree(void* ptr);    //checks if ptr is null before freeing memory
void* realloc(void *ptr, size_t size);    //resizes memory block on the heap pointed to by ptr
struct TreeNode* CreateNode(int flag);    //creates memory for a node and fills in data
struct TreeNode* InsertNode(struct TreeNode* listTreeNode, struct TreeNode* node, int flag);    //inserts a node into the list tree
char* InsertName(char* node);    //inserts a name into node subfield
void ClearInputBuffer(char* node, char* ptr);    //clears the input buffer after user input
int LexicoCompare(char* node, char* listNode);    //determines if name of node is to be sorted in left or right subtree of list tree
void PrintTreeInOrder(struct TreeNode* node, int flag);    //prints names of nodes in order
void PrintTreeInOrderReverse(struct TreeNode* node, int flag);    //prints names of nodes in reverse in-order
void PrintTreePreOrder(struct TreeNode* node, int flag);    //prints names of nodes in pre-order
void PrintTreePostOrder(struct TreeNode* node, int flag);    //prints names of nodes in post-order
struct Node* LeftRotation(struct Node* grandParent);    //Left Rotation
struct Node* RightRotation(struct Node* grandParent);    //Right Rotation
struct Node* LeftRightRotation(struct Node* grandParent);    //Left Right Rotation
struct Node* RightLeftRotation(struct Node* grandParent);    //Right Left Rotation
int RotationDeterminationCont(struct Node* node);    //helps
struct TreeNode* FindParentNode(struct TreeNode* parent, struct TreeNode* child, int flag);    //returns the parent node to child
void LinkParentChild(struct TreeNode* parent, struct TreeNode* child, int flag);    //links child node to parent
struct TreeNode* FindMaxNode(struct TreeNode* node);    //finds the max node in nodes tree
struct TreeNode* FindMinNode(struct TreeNode* node);    //finds the min node in nodes tree
void DeleteNode(struct TreeNode* treeNode, struct TreeNode* node, int flag);    //deletes node from treeNode and frees node memory
