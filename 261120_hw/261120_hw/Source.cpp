#include <iostream>
#include <assert.h>


//Toy klasinda -> id,color,volume(oyuncagin hecmi)
class Toy
{
	size_t id;
	std::string color;
	double volume;
public:
	static size_t static_id;
	Toy() {}

	Toy(const std::string& color, const double& volume)
	{
		setColor(color);
		setVolume(volume);
		setID(++static_id);
	}

	Toy(const Toy& toy)
	{
		setID(toy.getID());
		setColor(toy.getColor());
		setVolume(toy.getVolume());
	}

	Toy& operator=(const Toy& toy)
	{
		setID(toy.getID());
		setColor(toy.getColor());
		setVolume(toy.getVolume());
		return *this;
	}

	void setID(size_t id) { this->id = id; }

	size_t getID() const { return this->id; }

	void setColor(const std::string& color)
	{
		assert(!color.empty() && "Color cant be blank!");
		this->color = color;
	}

	std::string getColor() const { return this->color; }

	void setVolume(const double& volume)
	{
		assert(volume > 0 && "Volume must be greater than zero!");
		this->volume = volume;
	}

	double getVolume() const { return this->volume; }

	bool operator>=( Toy& second)
	{
		return this->volume >= second.volume;
	}

	bool operator<=( Toy& second)
	{
		return this->volume <= second.volume;
	}

	bool operator>( Toy& second)
	{
		return this->volume > second.volume;
	}

	bool operator<( Toy& second)
	{
		return this->volume < second.volume;
	}

	bool operator==(Toy& second)
	{
		return this->volume == second.volume;
	}

	bool operator==(size_t id)
	{
		return this->id == id;
	}

	friend std::ostream& operator <<(std::ostream&, const Toy&);
};
size_t Toy::static_id = NULL;

std::ostream& operator <<(std::ostream& out, const Toy& toy)
{
	out << "----------------------------------------" << std::endl;
	out << "ID: " << toy.getID() << std::endl;
	out << "Color: " << toy.getColor() << std::endl;
	out << "Volume: " << toy.getVolume() << std::endl;
	return out;
}

template <typename T>
class Node
{
public:
	T* data;
	Node<T>* left;
	Node<T>* right;
};

template <class T>
class BinaryTree
{
	Node<T>* root;

	void insert(Node<T>*, T&);
	bool search(Node<T>*, T&);
	void inOrder(Node<T>*);
	void preOrder(Node<T>*);
	void postOrder(Node<T>*);
	Node<T>* getNodeByID(Node<T>*, size_t);
	T deleteNode(Node<T>*&, const double&);


public:
	BinaryTree()
	{
		this->root = NULL;
	}

	void insert(T&);
	void inOrder();
	void preOrder();
	void postOrder();
	bool search(T&);
	T deleteNodeByVolume(const double &);
	T deleteNode(Node<T>*);
	T min();
	T max();

	Node<T>* min(Node<T>*);
	Node<T>* max(Node<T>*);

	Node<T>* getNodeByID(size_t ID);
};

template<class T>
void BinaryTree<T>::insert(T& data)
{
	if (this->root != NULL)
	{
		this->insert(this->root, data);
	}
	else
	{
		this->root = new Node<T>;
		this->root->data = new T(data);
		this->root->left = NULL;
		this->root->right = NULL;
	}
}

template<class T>
void BinaryTree<T>::insert(Node<T>* node, T& data)
{
	if (*(node->data) > data)
	{
		if (node->left != NULL)
		{
		this->	insert(node->left, data);
		}
		else
		{
			node->left = new Node<T>;
			node->left->data = new T(data);
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else if (*(node->data) <= data)
	{
		if (node->right != NULL)
		{
			this->insert(node->right, data);
		}
		else
		{
			node->right = new Node<T>;
			node->right->data = new T(data);
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}

}

template<class T>
void BinaryTree<T>::inOrder()
{
	if (this->root != NULL)
		this->inOrder(this->root);
	else
		std::cout << "Tree is empty" << std::endl;
}

template<class T>
void BinaryTree<T>::inOrder(Node<T>* node)
{
	// left root right
	if (node == NULL)
		return;

	this->inOrder(node->left);
	std::cout << *node->data << std::endl;
	this->inOrder(node->right);
}

template <class T>
void BinaryTree<T>::preOrder()
{
	if (this->root != NULL)
		this->preOrder(this->root);
	else
		std::cout << "Tree is empty" << std::endl;
}

template <class T>
void BinaryTree<T>::preOrder(Node<T>* node)
{
	// root left right
	if (node == NULL)
		return;

	std::cout << *node->data << std::endl;
	this->preOrder(node->left);
	this->preOrder(node->right);
}

template <class T>
void BinaryTree<T>::postOrder()
{
	if (this->root != NULL)
		this->postOrder(this->root);
	else
		std::cout << "Tree is empty!" << std::endl;
}

template<class T>
void BinaryTree<T>::postOrder(Node<T>* node)
{
	//root right left
	if (node == NULL)
		return;

	std::cout << *node->data;
	this->postOrder(node->right);
	this->postOrder(node->left);
}

template<class T>
bool BinaryTree<T>::search(T& data)
{
	if (this->root == NULL)
		return false;

	return this->search(this->root, data);
}

template<class T>
bool BinaryTree<T>::search(Node<T>* node, T& data)
{
	if (node == NULL)
		return false;

	bool status = false;
	if (*node->data == data)
		status = true;
	else if (*node->data > data)
		status = this->search(node->left, data);
	else if (*node->data < data)
		status = this->search(node->right, data);

	return status;
}

template <class T>
T BinaryTree<T>::min()
{
	T min;
	if (this->root == NULL)
		return min;

	Node<T>* tmp = this->root;
	while (tmp != NULL)
	{
		min = *tmp->data;
		tmp = tmp->left;
	}

	return min;
}

template <class T>
T BinaryTree<T>::max()
{
	T max;
	if (this->root == NULL)
		return max;

	Node<T>* tmp = this->root;

	while (tmp != NULL)
	{
		max = *tmp->data;
		tmp = tmp->right;
	}

	return max;
}

template <class T>
Node<T>* BinaryTree<T>::getNodeByID(size_t ID)
{
	if (this->root == NULL)
		return NULL;

	return getNodeByID(this->root, ID);
}

template<class T>
Node<T>* BinaryTree<T>::getNodeByID(Node<T>* node, size_t ID)
{
	if (node == NULL)
		return NULL;

	Node<T>* tmp = NULL;
	if (*node->data == ID)
		return node;

	tmp = getNodeByID(node->left, ID);

	if (tmp)
		return tmp;

	tmp = getNodeByID(node->right, ID);
	
	if (tmp)
		return tmp;

	if (tmp == NULL)
		return NULL;
}

template <class T>
T BinaryTree<T>::deleteNodeByVolume(const double & volume)
{
	if (this->root == NULL)
		return *this->root->data;

	return this->deleteNode(this->root, volume);
}

template <class T>
T BinaryTree<T>::deleteNode(Node<T>* node)
{
	if (this->root == NULL)
		return *this->root->data;
	else if (node == NULL)
		return *node->data;

	return this->deleteNode(this->root, node->data->getVolume());
}

template <class T>
T BinaryTree<T>::deleteNode(Node<T>*& node, const double& volume)
{
	if (node == NULL)
		return *node->data;


	if (volume > node->data->getVolume())
	{
		return this->deleteNode(node->right, volume);
	}
	else if (volume < node->data->getVolume())
	{
		return this->deleteNode(node->left, volume);
	}
	else
	{
		T tmp;
		if (node->left == NULL && node->right == NULL)
		{
			tmp = *node->data;
			delete node;
			node = NULL;
		}
		else if (node->left == NULL)
		{
			tmp = *node->data;
			Node<T>* tmp2 = node;
			node = node->right;
			delete tmp2;
			tmp2 = NULL;
		}
		else if (node->right == NULL)
		{
			tmp = *node->data;
			Node<T>* tmp2 = node;
			node = node->left;
			delete tmp2;
			tmp2 = NULL;
		}
		else
		{
			Node <T>* leftMax = max(node->left);
			tmp = *node->data;
			delete node->data;
			node->data = new T(*leftMax->data);

			deleteNode(node->left, leftMax->data->getVolume());
		}

		return tmp;
	}
}

template <class T>
Node<T>* BinaryTree<T>::min(Node<T>* node)
{
	if (node == NULL)
		return NULL;

	Node<T>* min = NULL;

	while (node != NULL)
	{
		min = node;
		node = node->left;
	}

	return min;
}

template <class T>
Node<T>* BinaryTree<T>::max(Node<T>* node)
{
	if (node == NULL)
		return NULL;

	Node<T>* max = NULL;

	while (node != NULL)
	{
		max = node;
		node = node->right;
	}

	return max;
}


void main()
{
	BinaryTree<Toy> bt;
	Toy t1("Black", 60);
	Toy t2("White", 30);
	Toy t3("Green", 45);
	Toy t4("Brown", 25);
	Toy t5("Red", 70);
	Toy t6("Yellow", 10);
	Toy t7("White", 28);
	Toy t8("Blue", 36);
	Toy t9("Orange", 58);
	Toy t10("Gray", 65);
	Toy t11("Dark green", 80);

	bt.insert(t1);
	bt.insert(t2);
	bt.insert(t3);
	bt.insert(t4);
	bt.insert(t5);
	bt.insert(t6);
	bt.insert(t7);
	bt.insert(t8);
	bt.insert(t9);
	bt.insert(t10);
	bt.insert(t11);

	//bt.inOrder();
	//bt.preOrder();
	//bt.postOrder();

	//std::cout << std::boolalpha << bt.search(t6) << std::endl;

	//std::cout << "Min: " << std::endl;
	//std::cout << bt.min() << std::endl;;

	//std::cout << "Max: " << std::endl;
	//std::cout << bt.max() << std::endl;;

	//Node<Toy>* tmp = bt.getNodeByID(5);

	//Node<Toy>* tmp2 = bt.min(tmp->right);

	//std::cout << *tmp2->data << std::endl;

	std::cout << bt.deleteNodeByVolume(10) << std::endl;

	std::cout << "After delete operation: " << std::endl;
	//bt.insert(t8);
	bt.inOrder();

}