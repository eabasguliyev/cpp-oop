#include <iostream>
#include <assert.h>

class MyString
{
	char* data;
	size_t length;

private:
	void setLength(int length)
	{
		this->length = length;
	}

	void checkData()const
	{
		assert(this->data && "There is not data!");
	}
public:
	MyString() :data(nullptr), length(0) {}
	MyString(const char* data)
	{
		setText(data);
	}

	MyString(const MyString& old)
	{
		setText(old.getText());
	}

	MyString& operator = (const MyString& old)
	{
		setText(old.getText());
		return *this;
	}

	void setText(const char* data)
	{
		size_t length = strlen(data);
		this->data = new char[length + 1];
		if (this->data)
		{
			strcpy_s(this->data, length + 1, data);
			setLength(length);
		}
	}

	const char* getText() const
	{
		return data;
	}

	int getLength() const
	{
		return length;
	}

	void append(const char* data)
	{
		checkData();
		size_t new_length = getLength() + strlen(data);

		char* new_data = new char[new_length + 1];

		if (new_data)
		{
			strcpy_s(new_data, getLength() + 1, this->data);
			strcpy_s(new_data + this->getLength(), strlen(data) + 1, data);

			delete[] this->data;

			this->data = new_data;

			new_data = nullptr;

			setLength(new_length);
		}
	}

	void sort(bool reverse = false)
	{
		checkData();
		if (reverse)
		{
			for (size_t i = 0; i < length - 1; i++)
			{
				bool swapped = false;
				for (size_t j = 0; j < length - 1; j++)
				{
					if (data[j] < data[j + 1])
					{
						char temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;

						swapped = true;
					}
				}

				if (!swapped)
					return;
			}
		}
		else
		{
			for (size_t i = 0, length = getLength() - 1; i < length; i++)
			{
				bool swapped = false;
				for (size_t j = 0; j < length; j++)
				{
					if (data[j] > data[j + 1])
					{
						char temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;

						swapped = true;
					}
				}

				if (!swapped)
					return;
			}
		}
	}

	char getFirstElement()const
	{
		checkData();
		return data[0];
	}

	char getLastElement() const
	{
		checkData();
		return data[getLength() - 1];
	}
	char* substr(int pos, int len)
	{
		checkData();
		assert(pos >= 0 && pos < getLength() && "Position must be greater than or equal to zero");
		assert(len > 0 && len <= getLength() && "Length must be greater than zero");
		assert(pos + len <= getLength() && "Out of range!");
		char* new_data = new char[len + 1]{};

		if (new_data)
		{
			for (size_t i = pos, j = 0; i < length && j < len; i++, j++)
			{
				new_data[j] = data[i];
			}

			return new_data;
		}
		return nullptr;
	}

	char * substr(int len)
	{
		checkData();
		assert(len > 0 && len <= getLength() && "Length must be greater than zero");

		char* new_data = new char[len + 1]{};

		if (new_data)
		{
			for (size_t i = 0; i < len; i++)
			{
				new_data[i] = data[i];
			}

			return new_data;
		}
		return nullptr;
	}

	int find(char character)
	{
		checkData();
		for (size_t i = 0; i < length; i++)
		{
			if (data[i] == character)
			{
				return i;
			}
		}
		return -1;
	}

	int find(const char* text)
	{
		checkData();
		assert(strlen(text) < length && "Data length must be less than original data");
		bool flag = true;
		for (size_t i = 0, length2= strlen(text); i < length - length2 + 1; i++)
		{
			if (data[i] == text[0])
			{
				for (size_t m = i + 1, n = 1; m < length2; m++, n++)
				{
					if (data[m] != text[n])
					{
						flag = false;
						break;
					}
				}

				if (flag)
					return i;
			}
		}
		return -1;
	}

	void clear()
	{
		if (data)
		{
			delete [] data;
			data = nullptr;
			length = 0;
		}
	}

	~MyString()
	{
		clear();
	}
};

class IntArray
{
	int* arr;
	size_t size;

private:
	void setArr(const int* arr, int size)
	{
		this->arr = new int[size];
		if (this->arr)
		{
			for (size_t i = 0; i < size; i++)
			{
				this->arr[i] = arr[i];
			}
			setSize(size);
		}
	}

	void setSize(size_t size)
	{
		this->size = size;
	}
public:
	void print() const;
	IntArray() :arr(nullptr), size(0) {}

	IntArray(const int* arr, int size)
	{
		setArr(arr, size);
	}

	IntArray(const IntArray& old)
	{
		setArr(old.getArr(), old.getSize());
	}

	IntArray& operator = (const IntArray& old)
	{
		setArr(old.getArr(), old.getSize());

		return *this;
	}

	const int* getArr() const
	{
		return arr;
	}

	int getSize() const
	{
		return size;
	}

	void pushFirst(int value)
	{
		size_t new_size = getSize() + 1;
		int* new_arr = new int[new_size];

		if (new_arr)
		{
			new_arr[0] = value;

			for (size_t i = 0, length = getSize(); i < length; i++)
			{
				new_arr[i + 1] = arr[i];
			}

			delete[] arr;

			arr = new_arr;
			new_arr = nullptr;
			setSize(new_size);
		}
	}

	void pushLast(int value)
	{
		size_t new_size = getSize() + 1;
		int* new_arr = new int[new_size];

		if (new_arr)
		{
			for (size_t i = 0, length = getSize(); i < length; i++)
			{
				new_arr[i] = arr[i];
			}

			new_arr[new_size - 1] = value;
			delete[] arr;

			arr = new_arr;

			new_arr = nullptr;

			setSize(new_size);
		}
	}
	
	void updateByIndex(int index, int value)
	{
		assert(index >= 0 && index < getSize() && "out of range!");

		this->arr[index] = value;
	}
	~IntArray()
	{
		delete[] arr;
	}
};

void IntArray::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int* arr = new int[5]{ 1,2,3,4,5 };
	IntArray new_arr(arr, 5);

	new_arr.print();
	std::cout << new_arr.getSize() << std::endl;
	
	new_arr.pushFirst(99);
	new_arr.print();
	std::cout << new_arr.getSize() << std::endl;

	new_arr.pushLast(111);
	new_arr.print();
	std::cout << new_arr.getSize() << std::endl;

	new_arr.updateByIndex(1, 51);
	new_arr.print();

	new_arr.updateByIndex(4, -9);
	new_arr.print();

	IntArray new_array2 = new_arr;

	new_array2.print();
	/*MyString s("Elgun");

	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;
	s.sort();
	s.append(" Abasquliyev");

	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;
	
	s.sort(true);
	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;
	s.sort();
	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;

	s.setText("Abasquliyev Elgun");

	std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;

	std::cout << s.substr(5, 1) << std::endl;
	std::cout << s.substr(5) << std::endl;

	std::cout << s.find('e') << std::endl;
	std::cout << s.find("Elgun") << std::endl;
	s.clear();

	//std::cout << "Text: " << s.getText() << std::endl;
	std::cout << "Length: " << s.getLength() << std::endl;*/
}