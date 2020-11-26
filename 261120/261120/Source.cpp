#include <iostream>


struct TreeNode
{
	int data;
	TreeNode* right;
	TreeNode* left;
};

class BinarySearchTree
{
	void insert(TreeNode*, int);
	bool search(TreeNode*, int);
	void inOrder(TreeNode*);
	void preOrder(TreeNode*);
	void postOrder(TreeNode*);
public:
	
	TreeNode* root;
	BinarySearchTree() {
		root = NULL;
	}
	int max();
	int min();

	void insert(int);
	bool search(int);
	void inOrder();
	void preOrder();
	void postOrder();
	TreeNode* deleteNode(int);
};

void BinarySearchTree::insert(int data)
{
	if (this->root != NULL)
	{
		insert(this->root, data);
	}
	else
	{
		this->root = new TreeNode;
		this->root->data = data;
		this->root->right = NULL;
		this->root->left = NULL;
	}
}
void BinarySearchTree::insert(TreeNode* node, int data)
{
	if (data < node->data)
	{
		if (node->left != NULL)
		{
			this->insert(node->left, data);
		}
		else
		{
			node->left = new TreeNode;
			node->left->data = data;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else if (data >= node->data)
	{
		if (node->right != NULL)
		{
			this->insert(node->right, data);
		}
		else
		{
			node->right = new TreeNode;
			node->right->data = data;
			node->right->right = NULL;
			node->right->left = NULL;
		}
	}
}
void BinarySearchTree::inOrder()
{
	if (this->root == NULL) std::cout << "Tree is empty!" << std::endl;
	else inOrder(this->root);
}
void BinarySearchTree::inOrder(TreeNode* node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		std::cout << node->data << ' ';
		inOrder(node->right);
	}
}
void BinarySearchTree::preOrder()
{
	if (this->root == NULL)
		std::cout << "Tree is empty!" << std::endl;
	else
		preOrder(this->root);
}
void BinarySearchTree::preOrder(TreeNode* node)
{
	if (node != NULL)
	{
		std::cout << node->data << ' ';
		preOrder(node->left);
		preOrder(node->right);
	}
}
void BinarySearchTree::postOrder()
{
	if (this->root == NULL) std::cout << "Tree is empty!" << std::endl;
	else
		postOrder(this->root);
}
void BinarySearchTree::postOrder(TreeNode* node)
{
	if (node != NULL)
	{
		std::cout << node->data << ' ';
		postOrder(node->right);
		postOrder(node->left);
	}
}
bool BinarySearchTree::search(int data)
{
	if (this->root == NULL)
	{
		return false;
	}
	else
	{
		return search(this->root, data);
	}
}
bool BinarySearchTree::search(TreeNode* node, int data)
{
	bool answer = false;
	if (node == NULL)
	{
		return false;
	}

	if (node->data == data)
	{
		answer = true;
	}
	else if(data < node->data)
	{
		answer = search(node->left, data);
	}
	else if (data > node->data)
	{
		answer = search(node->right, data);
	}

	return answer;

}
int BinarySearchTree::min()
{
	TreeNode* tmp = this->root;
	if (this->root == NULL)
		std::cout << "Tree is empty" << std::endl;
	else
	{
		while (tmp->left != NULL)
			tmp = tmp->left;
		return tmp->data;
	}
}
int BinarySearchTree::max()
{
	TreeNode* tmp = this->root;

	if (this->root == NULL)
		std::cout << "Tree is empty" << std::endl;
	else
	{
		while (tmp->right != NULL)
			tmp = tmp->right;
		return tmp->data;
	}
}

int main()
{
	BinarySearchTree bst;
	bst.insert(5);
	bst.insert(12);
	bst.insert(2);
	bst.inOrder();
	std::cout << std::endl;
	bst.preOrder();
	std::cout << std::endl;
	bst.postOrder();

	std::cout << std::endl;
	std::cout << std::boolalpha << bst.search(5) << std::endl;

	std::cout << bst.min() << std::endl;
	std::cout << bst.max() << std::endl;
}