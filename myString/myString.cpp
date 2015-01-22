// myString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MyString
{
	size_t _size;
	size_t _capacity;
	char *str_ele;
public:

	MyString();
    MyString(size_t capacity);
	MyString(size_t size, char str[]);
	virtual ~MyString();

	size_t size();
	size_t capacity() const;
	void reserve(const size_t newCapacity);

	char operator[](const size_t index);
	MyString& operator+=(MyString &str);
	char at(const size_t index);
	MyString operator=(MyString &str);

	void push_back(const char &str);
	char pop_back();
	MyString append( MyString &str);

	void insert(MyString &str, size_t index);
};

//construct
MyString::MyString() :_capacity(0), _size(0), str_ele(new char[_capacity])
{}

//string init
MyString::MyString(size_t capacity) :_capacity(capacity), _size(0), str_ele(new char[capacity])
{}
	
//string init2
MyString::MyString(size_t size, char str[]) : _size(size), _capacity(size << 2), str_ele(new char[size<<2])
{
	for (size_t i = 0; i < _size; i++)
	{
		str_ele[i] = str[i];	 
	}
}

//string destruct
MyString::~MyString()
{
	delete str_ele;
}

//string capacity
size_t MyString::capacity() const
{
	return _capacity;
}

//string size
size_t MyString::size()
{
	return _size;
}

//string enlarge capacity
void MyString::reserve(const size_t newCapacity)
{
	_capacity = newCapacity;
}

//sting []
char MyString::operator[](const size_t index)
{
	if (index<0 || index>=_size)
	{
		cout << "invalid index in []" << endl;
	}
	else
	{
		return str_ele[index];
	}
	
}

//string +=
MyString& MyString::operator+=(MyString &str)
{
	for (size_t i = 0; i < str._size; ++i)
	{
		if (_size >= _capacity)
		{
			reserve(_size << 2);
		}

		str_ele[_size] = str[i];
		++_size;
	}
	return *this;
}

//string =
MyString MyString::operator=(MyString &str)
{
	if (str_ele!=NULL)
	{
		delete str_ele;   //·ÀÖ¹ÄÚ´æÐ¹Â©
	}
	
	_size = str._size;
	_capacity = str._capacity;
	
	str_ele = new char[_capacity];

	for (size_t i = 0; i < str._size; i++)
	{
		str_ele[i] = str[i];
	}
	return *this;

}

// string add new element
void MyString::push_back(const char &str)
{
	if (_size >= _capacity)
	{
		reserve(_size << 2);		
	}
	str_ele[_size] = str;
	++_size;
}

//string at
char MyString::at(const size_t index)
{
	if (index >= _size||index<0)
	{
		cout << "invalid index in at" << endl;
	
	}
	else
	{
		return str_ele[index];
	}
}

//string pop_back
char MyString::pop_back()
{
	if (str_ele != NULL)
	{
		--_size;
		return str_ele[_size];
        	
	}
}

//string append
MyString MyString::append(MyString &str)
{
	

	for (size_t i = 0; i < str._size; ++i)
	{
		if (_size >= _capacity)
		{
			reserve(_size << 2);
		}

		str_ele[_size] = str[i];
		++_size;		
	}
	return *this;
	
}

//string insert
void MyString::insert(MyString &str, size_t index)
{
	if (index > _size || index < 0)
	{
		cout << "invalid index in insert";
	}
	else
	{
		size_t oldsize = _size;
		size_t newsize = str._size;
		size_t ll = oldsize - index;

		_size = oldsize + newsize;
		
		if (_size > _capacity)
		{
			reserve(_size << 2);
		}
				
		for (size_t i = 0; i < _size - index; ++i)
		{			
			if (i < ll)
			{
				str_ele[_size - i -1 ] = str_ele[oldsize - 1];
				--oldsize;	
			}
			else
			{
				str_ele[_size - i - 1] = str[newsize - 1];
				--newsize;
			}
		}
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	MyString mystr(13,"myworld------");
	MyString mystr2(6, "abcdef");
	MyString mystr3 = mystr;
	

	cout << "the capacity:" << mystr.capacity() << endl;
	cout << "the size:" << mystr.size() << endl;	

	//mystr.push_back('w');

	mystr.insert(mystr2, 2);

	for (size_t i = 0; i < mystr3.size(); ++i)
	{
		cout << mystr3.at(i)<<endl;
	}
	
	cin.get();

	return 0;
}

