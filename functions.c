#include functions.h

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* CreateNode(int flag) {    //creates memory for a node and fills in data returning struct of type TreeNode
	if (flag == tree_list) {
		struct TreeNode* temp = malloc(sizeof(struct TreeNode));
		(*temp).address = NULL;
		(*temp).left = NULL;
		(*temp).right = NULL;
		(*temp).firstName = NULL;
		(*temp).lastName = NULL;
		return temp;
	}

	else {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		(*temp).left = NULL;
		(*temp).right = NULL;
		(*temp).address = NULL;
		return (struct TreeNode*) temp;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* InsertNode(struct TreeNode* listTreeNode, struct TreeNode* node, int flag) {    //inserts a node into the list tree
	switch (flag) {
	case tree_list: {
		if (listTreeNode == NULL) {
			//listTreeNode = CreateNode(1);
			//(*listTreeNode).address = node;
			listTreeNode = node;
		}

		else if (LexicoCompare((*node).lastName, (*listTreeNode).lastName))
			(*listTreeNode).right = InsertNode((*listTreeNode).right, node, tree_list);

		else
			(*listTreeNode).left = InsertNode((*listTreeNode).left, node, tree_list);

		break;
	}

	default: {
		if (listTreeNode == NULL || (*listTreeNode).address == NULL) {
			listTreeNode = CreateNode(user_list);
			(*listTreeNode).address = node;
		}

		else if (LexicoCompare((*node).lastName, (*((*listTreeNode).address)).lastName))
			(*listTreeNode).right = InsertNode((*listTreeNode).right, node, user_list);

		else
			(*listTreeNode).left = InsertNode((*listTreeNode).left, node, user_list);

		break;
	}
	}

	return listTreeNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* InsertName(char* nodeName) {    //creates memory for node name (limit 25 characters), adds null terminator and resizes memory
	size_t i = 0;							//create another function which creates memory and only have function take a char* and
	char c = '\0';						//insert char* value into memory address (parameter/argument) possibly
	char* ptr = NULL;
	char name[name_length + name_length];
	printf("Enter first name (limit 25 characters):\n");
	nodeName = (char*)malloc(sizeof(char) * (name_length + 1));
	while ((c = getchar()) != '\n' && c != EOF && i < name_length)
		*(name + i++) = c;
	*(name + i) = '\0';
	snprintf(nodeName, name_length, "%s", (const char*)name);
	if (i >= name_length) { //right at 25 character on input, theres nothing left in stdin for getchar(), over 25 will be cleared
		char c = '\0';
		while ((c = getchar()) != EOF && c != '\n');
	}
	ClearInputBuffer((char*)nodeName, ptr); //clears buffer
	return nodeName;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClearInputBuffer(char* node, char* ptr) {    //removes '\n' from node and clears input buffer
	//char c = 0;

	if ((ptr = strchr((const char*)node, '\n')) != NULL)
		*ptr = '\0';

	//while ((c = getchar()) != EOF && c != '\n');
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sfree(void* ptr) {
	if (ptr != NULL)
		free(ptr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LexicoCompare(char* node, char* listNode) {    //returns 1 if name in node is larger than list node name, which sorts in right
	if (*node > *listNode)						   //subtree, else node is added to left subtree (used for other functions)
		return 1;

	else if (*node == '\0' || *listNode == '\0')
		return 0;

	else if (*node == *listNode)
		LexicoCompare((node + 1), (listNode + 1));

	else
		return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintTreeInOrder(struct TreeNode* node, int flag) {    //prints names of nodes in-order
	if (node == NULL) {
		printf("ERROR: Tree is empty\n");
		return;
	}

	if ((*node).left != NULL)
		PrintTreeInOrder((*node).left, flag);

	switch (flag) {
	case tree_list: {
		printf("%s ", (*node).lastName);
		break;
	}

	default: {
		printf("%s ", (*((struct TreeNode*)((*((struct Node*)node)).address))).lastName);
		break;
	}
	}

	if ((*node).right != NULL)
		PrintTreeInOrder((*node).right, flag);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintTreeInOrderReverse(struct TreeNode* node, int flag) {    //prints names of nodes in reverse in-order
	if (node == NULL) {
		printf("ERROR: Tree is empty\n");
		return;
	}

	if ((*node).right != NULL)
		PrintTreeInOrderReverse((*node).right, flag);

	switch (flag) {
	case tree_list: {
		printf("%s ", (*node).lastName);
		break;
	}

	default: {
		printf("%s ", (*((struct TreeNode*)((*((struct Node*)node)).address))).lastName);
		break;
	}
	}

	if ((*node).left != NULL)
		PrintTreeInOrderReverse((*node).left, flag);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintTreePreOrder(struct TreeNode* node, int flag) {    //prints names of nodes in pre-order
	if (node == NULL) {
		printf("ERROR: Tree is empty\n");
		return;
	}

	switch (flag) {
	case tree_list: {
		printf("%s ", (*node).lastName);
		break;
	}

	default: {
		printf("%s ", (*((struct TreeNode*)((*((struct Node*)node)).address))).lastName);
		break;
	}
	}

	if ((*node).left != NULL)
		PrintTreePreOrder((*node).left, flag);

	if ((*node).right != NULL)
		PrintTreePreOrder((*node).right, flag);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintTreePostOrder(struct TreeNode* node, int flag) {    //prints names of nodes in post-order
	if (node == NULL) {
		printf("ERROR: Tree is empty\n");
		return;
	}

	if ((*node).left != NULL)
		PrintTreePostOrder((*node).left, flag);

	if ((*node).right != NULL)
		PrintTreePostOrder((*node).right, flag);

	switch (flag) {
	case tree_list: {
		printf("%s ", (*node).lastName);
		break;
	}

	default: {
		printf("%s ", (*((struct TreeNode*)((*((struct Node*)node)).address))).lastName);
		break;
	}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteNode(struct TreeNode* treeNode, struct TreeNode* node, int flag) {    //deletes node from treeNode and frees node memory
	struct TreeNode* parent;

	switch (flag) {
	case tree_list: {
		parent = FindParentNode(treeNode, node, 1);
		struct TreeNode* temp;

		if ((*node).left == NULL && (*node).right == NULL) {
			if (LexicoCompare((*node).lastName, (*parent).lastName))
				(*parent).right = NULL;
			else
				(*parent).left = NULL;
			temp = node;
		}

		else if ((*node).left != NULL && (*node).right != NULL || parent == node) {
			struct TreeNode* grandParent = parent;
			temp = node;
			node = FindMaxNode((*node).left);
			parent = FindParentNode(treeNode, node, 1);

			if (parent == temp) {
				if (LexicoCompare((*node).lastName, (*grandParent).lastName))
					(*grandParent).right = node;
				else
					(*grandParent).left = node;
				(*node).right = (*parent).right;
			}
			else {
				(*parent).right = (*node).left;
				(*node).left = (*temp).left;
				(*node).right = (*temp).right;
				if (LexicoCompare((*node).lastName, (*grandParent).lastName))
					(*grandParent).right = node;
				else
					(*grandParent).left = node;
			}
		}

		else {
			temp = node;

			if ((*node).left != NULL) {
				node = (*node).left;
				LinkParentChild(parent, node, tree_list);
			}

			else {
				node = (*node).right;
				LinkParentChild(parent, node, tree_list);
			}
		}

		sfree((void*)temp);
		return;
	}

	default: {
		parent = FindParentNode(treeNode, node, user_list);
		struct TreeNode* temp;

		if (LexicoCompare((*node).lastName, (*((struct TreeNode*)((*((struct Node*)parent)).address))).lastName))
			temp = (*parent).right;
		else
			temp = (*parent).left;

		if ((*temp).left == NULL && (*temp).right == NULL) {
			if ((*parent).left == temp)
				(*parent).left = NULL;
			else
				(*parent).right = NULL;
		}

		else if ((*node).left != NULL && (*node).right != NULL || parent == node) {
			struct TreeNode* grandParent = temp;
			temp = FindMaxNode((*grandParent).left);
			parent = FindParentNode(treeNode, (*temp).address, user_list);
			(*grandParent).address = (*temp).address;
			(*parent).right = (*temp).left;
		}

		else {
			struct TreeNode* child;
			if ((*temp).left != NULL) {
				child = (*temp).left;
				LinkParentChild(parent, child, user_list);
			}

			else {
				child = (*temp).right;
				LinkParentChild(parent, child, user_list);
			}
		}
		sfree((void*)temp);
		return;
	}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* FindParentNode(struct TreeNode* parent, struct TreeNode* child, int flag) {    //returns the parent node to child
	switch (flag) {
	case tree_list: {
		if (parent == child)
			return parent;

		else if ((*parent).left == child || (*parent).right == child)
			return parent;

		else if (LexicoCompare((*child).lastName, (*parent).lastName)) //maybe implement switch case, else if is flag and switch case is 1 or 0 with default
			FindParentNode((*parent).right, child, tree_list);

		else if (LexicoCompare((*child).lastName, (*parent).lastName) == 0)
			FindParentNode((*parent).left, child, tree_list);

		else
			return NULL;

		return;
	}

	default: {
		if ((*parent).left != NULL)
			if ((*((*parent).left)).address == child)
				return parent;

		if ((*parent).right != NULL)
			if ((*((*parent).right)).address == child)
				return parent;

		if ((*parent).address == child)
			return parent;

		else if (LexicoCompare((*child).lastName, (*((struct TreeNode*)((*((struct Node*)parent)).address))).lastName))
			FindParentNode((*parent).right, child, user_list);

		else if (LexicoCompare((*child).lastName, (*((struct TreeNode*)((*((struct Node*)parent)).address))).lastName) == 0)
			FindParentNode((*parent).left, child, user_list);

		else
			return NULL;

		return;
	}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LinkParentChild(struct TreeNode* parent, struct TreeNode* child, int flag) {    //links child node to parent
	switch (flag) {
	case tree_list: {
		if (LexicoCompare((*child).lastName, (*parent).lastName))
			(*parent).right = child;

		else
			(*parent).left = child;
		break;
	}

	default: {
		if (LexicoCompare((*((struct TreeNode*)((*((struct Node*)child)).address))).lastName, (*((struct TreeNode*)((*((struct Node*)parent)).address))).lastName))
			(*parent).right = child;

		else
			(*parent).left = child;
		break;
	}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* FindMaxNode(struct TreeNode* node) {    //finds the max node in nodes tree
	if (node == NULL)
		return ((struct TreeNode*) - 1);

	else if ((*node).right == NULL)
		return node;

	FindMaxNode((*node).right);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* FindMinNode(struct TreeNode* node) {    //finds the min node in nodes tree
	if (node == NULL)
		return ((struct TreeNode*) - 1);

	else if ((*node).left == NULL)
		return node;

	FindMinNode((*node).left);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t FindHeight(struct TreeNode* node) {    //returns the number of edges (branches) not level of nodes
	if (node == NULL)
		return (-1);

	size_t left = FindHeight((*node).left) + 1;
	size_t right = FindHeight((*node).right) + 1;

	if (left > right)
		return left;
	else
		return right;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TreeNode* CheckTreeBalance(struct TreeNode* node) {
	if (node == NULL)
		return 0;

	size_t left = FindHeight(node);
	size_t right = FindHeight(node);

	if (left > right + 1)
		return node;
	else if (left + 1 < right)
		return node;

	CheckTreeBalance((*node).left);
	CheckTreeBalance((*node).right);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct Node* LeftRotation(struct Node* grandParent) {    //Left Rotation
	struct Node* parent = (*grandParent).right;
	(*grandParent).right = (*parent).left;
	(*parent).left = grandParent;
	return parent;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node* RightRotation(struct Node* grandParent) {    //Right Rotation
	struct Node* parent = (*grandParent).left;
	(*grandParent).left = (*parent).right;
	(*parent).right = grandParent;
	return parent;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node* LeftRightRotation(struct Node* grandParent) {    //Left Right Rotation
	struct Node* parent = (*grandParent).left;
	(*grandParent).left = LeftRotation(parent);
	return RightRotation(grandParent);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node* RightLeftRotation(struct Node* grandParent) {    //Right Left Rotation
	struct Node* parent = (*grandParent).right;
	(*grandParent).right = RightRotation(parent);
	return LeftRotation(grandParent);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int RotationDeterminationCont(struct Node* node) {    //helps
	if ((*node).left != NULL && (*node).right == NULL)
		return 1;

	else if ((*node).left == NULL && (*node).right != NULL)
		return 2;

	else if ((*node).left != NULL && (*node).right != NULL) {
		//struct Node* right = (*node).right;
		//struct Node* left = (*node).left;
		return (LexicoCompare((*(*node).right).lastName, (*(*node).left).lastName)) ? 2 : 1;
	}

	else
		return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node* CheckFriends(struct Node* treeNode, struct TreeNode* node) {    //checks treeNodes list to search for node, if match address of
	if (treeNode == NULL || node == NULL)
		return 0;

	if ((*treeNode).address == node)
		return 1;

	switch (LexicoCompare((*node).lastName, (*(struct TreeNode*)(*treeNode).address).lastName)) {
	case 0: {
		CheckFriends((*treeNode).left, node);
		return;
	}
	case 1: {
		CheckFriends((*treeNode).right, node);
		return;
	}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
