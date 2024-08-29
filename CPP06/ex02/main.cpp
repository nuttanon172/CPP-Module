#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base;
class A;
class B;
class C;

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	std::cout << "-------------------------" << std::endl;
	A A1;
	B B1;
	C C1;
	identify(A1);
	identify(B1);
	identify(C1);

	std::cout << "-------------------------" << std::endl;
	A *ptrA = new A();
	B *ptrB = new B();
	C *ptrC = new C();
	identify(ptrA);
	identify(ptrB);
	identify(ptrC);
	delete ptrA;
	delete ptrB;
	delete ptrC;

	std::cout << "-------------------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *ptr = generate();
		identify(ptr);
		sleep(1);
		delete ptr;
	}
}

Base *generate(void)
{
	std::srand(std::time(0));
	if (std::rand() % 3 == 0)
		return (new A());
	else if (std::rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "ptr: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "ptr: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "ptr: C" << std::endl;
}

void identify(Base &p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "ptr: A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "ptr: B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "ptr: C" << std::endl;
}
