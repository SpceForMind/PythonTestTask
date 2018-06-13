
#include <cstdio>//stdio.h
#include <iostream>

//using namespace std; 
using std::cout;//only cout
using std::endl;


//interface
class  A
{
public:
	virtual void hello() = 0;
};


class B: public A
{
	public:
	void hello()
	{
		cout<<"B!" <<endl;
	}
};


class C: public A
{
	public:
	void hello()
	{
		cout<< "C" <<endl;
	}
};


int main()
{
	cout << "A: " << sizeof(A) << endl;
	cout << "B: " << sizeof(B) << endl;
	cout << "C: " << sizeof(C) << endl;

	A *a[3];
	a[0] = new C();
	a[1] = new B();
	a[2] = new C();
	for(int i = 0; i < 3; ++i)
		a[i]->hello();

	return 0;
}	


