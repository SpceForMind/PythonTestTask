
#include <iostream>

using std::cout;
using std::endl;


class StackException: public std::exception
{
public:
	const char *what()
	{
		return "Stack error!";
	}
};

class StackEmptyException: public StackException
{
public:
	const char *what()
	{
		return "Stack is empty!";
	}	
};

class Stack
{
private:
	int *arr;
	int top;
	int capacity; //
public:
	
	//constructor
	Stack(int size)
	{	
		capacity = size;
		arr = new int[capacity];
		top = -1;
	}
	//destructor
	~Stack()
	{
		delete[] arr;
	}

	bool Pop(int &val)
	{
		if(IsEmpty())
			return false;
		val = arr[top];
		--top;
		return true;
	}

	bool Push(int value)
	{
		if(top == capacity - 1)
			return false;
		++top;
		arr[top] = value;
		return true;
	}

	int Top()
	{
		if(IsEmpty())
			throw StackException();
		return arr[top];
	}

	int IsEmpty()
	{
		return top == -1;
	}
};	

Stack CreateStack()
{
	Stack stack(10);
	return stack;
}



int main()
{
	Stack s(10);
	
	try
	{
		s.Top();
	}
	catch(StackEmptyException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(StackException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}


	for(int i = 0; i < 1000; ++i)
		if(!s.Push(i))
		{
			cout << "Push error!\n";
			break;
		}

	int res;
	while(s.Pop(res))
		cout << "res = " << res <<endl;

	return 0;
}
