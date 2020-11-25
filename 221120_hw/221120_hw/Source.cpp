#include <iostream>
#include <assert.h>


class Level
{
	std::string name;
	std::string diff;
public:
	Level() {};
	Level(const std::string& name, const std::string diff)
	{
		setName(name);
		setDiff(diff);
	}
	void setName( std::string name)
	{
		this->name = name;
	}

	void setDiff(const std::string& diff)
	{
		this->diff = diff;
	}

	std::string getName() const { return this->name; }
	std::string getDiff() const { return this->diff; }
};


template <typename T>
class Node
{
public:
	T* data;
	Node* next;
};

template <class T>
class LinkedList
{
	Node<T>* head;

	size_t count;
public:
	LinkedList() {}

	void pushFirst(T& value)
	{
		Node<T>* node = new Node<T>;
		node->data = new T;
		node->data->setName(value.getName());
		node->data->setDiff(value.getDiff());

		if (head != nullptr)
			node->next = head;
		else
			node->next = NULL;
		head = node;

		count++;
	}
	
	void pushLast(T& value)
	{
		Node<T>* node = new Node<T>;
		node->data = new T;
		node->data->setName(value.getName());
		node->data->setDiff(value.getDiff());
		node->next = NULL;
		Node<T>* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}

		last->next = node;
		count++;
	}

	void deleteLast()
	{
		if (head)
		{
			Node<T>* tmp = head;
			Node<T>* last = head;;

			while (last->next != NULL)
			{
				if (tmp->next->next != NULL)
				{
					tmp = tmp->next;
				}
				last = last->next;
			}

			if (tmp != last)
			{
				delete last;

				tmp->next = NULL;
			}
			else
			{
				delete head;
				head = nullptr;
			}
		}
	}

	void deleteFirst()
	{
		if (head)
		{
			Node<T>* new_head = nullptr;;

			if (head->next != NULL)
			{
				new_head = head->next;
			}
			delete head;

			head = new_head;
		}
	}

	void insertByIndex(T& level, size_t index)
	{
		assert(count >= index && "Index out of range");
		
		if (index == 0)
		{
			pushFirst(level);
		}
		else
		{
			size_t counter = 0;
			Node<T>* tmp = head;
			Node<T>* new_node = new Node<T>;

			new_node->data = new T(level);

			while (++counter != index)
			{
				tmp = tmp->next;
			}
			new_node->next = tmp->next;

			tmp->next = new_node;
		}
	}

	void deleteByIndex(size_t index)
	{
		assert(count > index && "Index out of range");

		if (index == 0)
		{
			deleteFirst();
		}
		else
		{
			size_t counter = 1;
			Node<T>* new_node = nullptr;
			Node<T>* tmp = head;
			while (index != counter)
			{
				tmp = tmp->next;
				counter++;
			}
			new_node = tmp->next->next;
			delete tmp->next;
			tmp->next = new_node;
		}
	}

	void deleteAfter(Node<T>* node)
	{
		Node<T>* tmp;
		if (node->next != NULL)
		{
			tmp = node->next->next;
			delete node->next;
			node->next = tmp;
		}
	}

	void setHead(Node<T>* head)
	{
		assert(count == 0 && "First set count!");
		this->head = head;
	}

	void setCount(int count)
	{
		assert(count > 0 && "Count must be greater than zero");
		this->count = count;
	}

	Node<T>* getNode(size_t index)
	{
		assert(index >= 0 && index < count && "Index out of range");
		size_t counter = 0;
		Node<T>* tmp = head;
		while (counter++ != index)
		{
			tmp = tmp->next;
		}

		return tmp;
	}

	void print() const
	{
		Node<T>* tmp = head;
		while (tmp != NULL)
		{
			std::cout << "Name: " << tmp->data->getName() << std::endl;
			std::cout << "Diff: " << tmp->data->getDiff() << std::endl;
			tmp = tmp->next;
		}
	}

	size_t getCount() const
	{
		return this->count;
	}

	Node<T>* getHead() const
	{
		return head;
	}

};


void main()
{
	LinkedList<Level> ll;

	Level n;
	n.setName("run");
	n.setDiff("easy");

	ll.pushFirst(n);

	n.setName("catch");
	n.setDiff("normal");

	ll.pushFirst(n);

	n.setName("alive");
	n.setDiff("hard");

	ll.pushLast(n);

	ll.print();


	std::cout << "-------------------------------------" << std::endl;

	ll.deleteAfter(ll.getNode(1));

	ll.print();
	/*ll.deleteByIndex(2);

	std::cout << "---------------------------\n";
	ll.print();*/

	
	/*std::cin.get();
	n.setName("die");
	n.setDiff("easy");

	ll.insertByIndex(n, 3);

	std::cout << "---------------------------\n";
	ll.print();*/

	/*std::cout << "---------------------------\n";

	ll.deleteLast();

	ll.print();
	std::cout << "---------------------------\n";
	ll.deleteLast();

	ll.print();

	std::cout << "---------------------------------\n";
	ll.deleteLast();

	ll.print();

	std::cout << "---------------------------------\n";
	ll.deleteLast();

	ll.print();*/


	/*std::cout << "---------------------------------\n";

	ll.print();

	ll.deleteFirst();

	std::cout << "---------------------------------\n";

	ll.print();

	ll.deleteFirst();

	std::cout << "---------------------------------\n";

	ll.print();


	std::cout << "---------------------------------\n";


	ll.deleteFirst();

	ll.print();
	std::cout << "---------------------------------\n";

	ll.deleteFirst();

	ll.print();
	std::cout << "---------------------------------\n";*/
}