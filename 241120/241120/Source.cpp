#include <iostream>

class Node
{
public:
	std::string data;
	Node* next;
	Node* prev;
	

	Node() : data(""), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList
{
	Node* head; // front, first
	Node* tail; // end , last
public:
	
	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	DoubleLinkedList(Node* head, Node* tail)
	{
		this->head = head;
		this->tail = tail;
	}

	void addFront(const std::string&);
	void addAfter(Node*, const std::string&);
	void addEnd(const std::string&);
	void deleteNode(Node*);
	void forwardTraverse();
	void backwardTraverse();
	Node* getNode(size_t);
	void deleteFirst();
	void deleteLast();
	void deleteByData(const std::string&);
	void insertByIndex(size_t, const std::string&);
	// traverse == show
};

void DoubleLinkedList::forwardTraverse()
{
	Node* traverse = head;

	while (traverse != NULL)
	{
		std::cout << traverse->data << std::endl;
		traverse = traverse->next;
	}std::cout << std::endl;
}

void DoubleLinkedList::backwardTraverse()
{
	Node* backward = tail;

	while (backward != NULL)
	{
		std::cout << backward->data << std::endl;
		backward = backward->prev;
	}std::cout << std::endl;
}

void DoubleLinkedList::addFront(const std::string& value)
{
	Node* node = new Node();
	node->data = value;
	node->prev = NULL;
	node->next = head;

	if (head == NULL)
	{
		tail = node;
	}
	else
	{
		head->prev = node;
	}
	head = node;
}

void DoubleLinkedList::addEnd(const std::string& value)
{
	Node* node = new Node;
	node->data = value;
	node->prev = tail;
	node->next = NULL;

	if (tail == NULL)
	{
		head = node;
	}
	else
	{
		tail->next = node;
	}

	tail = node;
}

void DoubleLinkedList::deleteNode(Node* node)
{
	if (head == NULL)
	{
		return;
	}
	else if (node == head)
	{
		/*Node* new_head = head->next;
		new_head->prev = NULL;
		delete head;
		head = new_head;*/

		head = node->next;
		head->prev = NULL;
		//delete node;
	}
	else if (node == tail)
	{
		/*Node* new_tail = tail->prev;
		new_tail->next = NULL;
		delete tail;
		tail = new_tail;*/
		tail = tail->prev;
		tail->next = NULL;
		//delete node;
	}
	else
	{
		/*Node* prev_node = node->prev;
		Node* next_node = node->next;

		delete node;
		prev_node->next = next_node;
		next_node->prev = prev_node;*/
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	delete node;
}

void DoubleLinkedList::addAfter(Node* node, const std::string& value)
{
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = node->next;
	new_node->prev = node;
	node->next->prev = new_node;
	node->next = new_node;

	if (new_node->next == NULL)
	{
		tail = new_node;
	}

}

Node* DoubleLinkedList::getNode(size_t index)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		size_t counter = 0;
		Node* node = head;
		while (counter < index && node != NULL)
		{
			node = node->next;
			counter++;
		}
		if (counter != index)
			return NULL;
		return node;
	}

}

void DoubleLinkedList::deleteFirst()
{
	if (head == NULL)
		return;

	Node* new_head = head->next;
	new_head->prev = NULL;
	delete head;
	head = new_head;
}

void DoubleLinkedList::deleteLast()
{
	if (tail == NULL)
		return;
	Node* new_tail = tail->prev;
	new_tail->next = NULL;
	delete tail;
	tail = new_tail;
}

void DoubleLinkedList::deleteByData(const std::string& value)
{
	Node* current_node = NULL;
	Node* head = this->head;
	while (head != NULL)
	{
		if (head->data == value)
		{
			current_node = head;
			break;
		}

		head = head->next;
	}

	if (current_node == NULL)
		return;

	Node* tmp = current_node;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;

	delete current_node;
}

void DoubleLinkedList::insertByIndex(size_t index, const std::string& value)
{
	Node* shifted_node = getNode(index);

	if (shifted_node != NULL)
	{
		Node* node = new Node;
		node->data = value;

		if (shifted_node->prev != NULL)
		{
			shifted_node->prev->next = node;
			node->prev = shifted_node->prev;	
			
		}
		else
			head = node;
		node->next = shifted_node;
		shifted_node->prev = node;
	}
	else
		return;
}

void main()
{
	Node* first = NULL;
	Node* second = NULL;
	Node* third = NULL;


	first = new Node;
	second = new Node;
	third = new Node;

	first->data = "first";
	first->next = second;
	first->prev = NULL;

	second->data = "second";
	second->next = third;
	second->prev = first;

	third->data = "third";
	third->next = NULL;
	third->prev = second;
	
	DoubleLinkedList dll(first, third);

	dll.forwardTraverse();

	//dll.backwardTraverse();

	std::cout << "New node added to front" << std::endl;

	dll.addFront("zero");

	dll.forwardTraverse();

	std::cout << "New node added to end" << std::endl;

	dll.addEnd("fourth");

	dll.forwardTraverse();

	std::cout << "New node added to end" << std::endl;

	dll.addEnd("fifth");
	dll.forwardTraverse();
	
	dll.addAfter(second, "second");

	std::cout << "New node added after second node" << std::endl;

	dll.forwardTraverse();

	std::cout << "Second node deleted!" << std::endl;

	Node* tmp = dll.getNode(2);
	dll.deleteNode(tmp);

	dll.forwardTraverse();

	std::cout << "First node deleted!" << std::endl;

	dll.deleteNode(dll.getNode(0));

	dll.forwardTraverse();

	std::cout << "Last node deleted!" << std::endl;

	dll.deleteNode(dll.getNode(4));

	dll.forwardTraverse();


	std::cout << "'Third' node deleted" << std::endl;
	dll.deleteByData("third");

	dll.forwardTraverse();

	std::cout << "'fifth' node deleted" << std::endl;
	dll.deleteByData("fifth");

	dll.forwardTraverse();

	std::cout << "Fifth inserted" << std::endl;

	dll.insertByIndex(2, "fifth");

	dll.forwardTraverse();


	std::cout << "Backward traverse" << std::endl;
	dll.backwardTraverse();
}
	/*int arr[4]{ 1,2,3,4 };

	std::cout << *(arr + 3) << std::endl;*/