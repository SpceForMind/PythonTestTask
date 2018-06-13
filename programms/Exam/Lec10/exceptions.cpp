
#include <iostream>


int f(int n)
{
	try
	{
		if(n > 1)
			throw 100;
	}
	catch(int e)
	{
		std::cout << "Exception1\n";
		throw 3.14;
	}	
}


int main()
{
	try
	{
		f(10);
	}
	catch(int e)
	{
		std::cout << "catched: " << e << std::endl;
	}
	catch(char const *e)
	{	
		std::cout << "catched: " << e << std::endl;
	}
	catch(...)
	{
		std::cout << "Another exception!\n";
	}

	return 0;
}
