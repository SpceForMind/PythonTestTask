
#include <cstdio>//stdio.h
#include <iostream>

//using namespace std; 
using std::cout;//only cout
using std::endl;

class  A
{
	int a;
	int b;
public:
	//defautlt constructor
	A()
	{
		cout << "A()" << endl;
	}
	//constructor 
	A(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "A(int ,int)" << endl;
	}
	void sum()
	{
		std::cout << this;
		std::cout << "sum(): " << a + b << std::endl;
	}
	~A()
	{
		cout << "~A(" << a << " " << b << ")" << endl;
	}
};


class B: public A
{
	


};


A f(int n)
{
	A a(n, n * n);
	return a;
}



int main()
{
	a = f(10);
//	std::cout << &a << std::endl;
//	std::cout << sizeof(a) << std::endl;
	a.sum();	

	return 0;
}


